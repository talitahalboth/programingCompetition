#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define unicos(X) (X).erase(unique(all(X)),(X).end())
#define NL <<"\n"
#define EPS 1e-6
#define MOD 1000000007
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

vector<vector<int>>tree;

int pai[2512];
int dist[2512];
pii removido;
pii inserido;
void dfs(int u, int p, int d)
{
    // printf("u:%dp: %d\n",u,p );
    if (dist[u]!=-1)
        return;
    dist[u] = d;
    pai[u] = p;
    for (auto v: tree[u])
    {

        // printf("filho de %d : %d\n",u,v );
        if (!((u == removido.fi && v == removido.se) ||
            (v == removido.fi && u == removido.se)))
        {
            // printf("removidos: %d %d\n",removido.fi, removido.se );
            // printf("chamou pro filho de %d : %d\n",u,v );
            dfs(v,u,d+1);
        }
    }
    if(u == inserido.fi)
        dfs(inserido.se,u,d+1);
    if(u == inserido.se)
        dfs(inserido.fi,u,d+1);
}
int d;
int _dfs(int u)
{
    d=0;
    // printf("u:%d, d: %d\n",u,d );
    for (int i = 0; i < 2512; ++i)
    {
        pai[i]=-1;
        dist[i]=-1;
    }
    // memset(pai, -1, sizeof pai);
    // memset(dist, -1, sizeof dist);
    dfs(u,-1,0);

    int umax=0;
    for (int i = 0; i < tree.size(); ++i)
    {
        if (dist[i] > dist[umax]) umax = i;
    }
    d = dist[umax];
    return umax;


}

int achaCentro()
{
    inserido=mp(-1,-1);
    removido=mp(-1,-1);
    int x = _dfs(0);
    // printf("x eh %d\n",x );
    int u = _dfs(x);
    vector<int> caminho;
    caminho.clear();
    // printf("u eh: %d\n",u );
    while (pai[u]!=-1)
    {
        caminho.pb(u);
        u= pai[u];
    }
    caminho.pb(u);
    int minDiam = iinf;
    pii melhorInsere;
    pii melhorRemove;
    inserido = mp(-1,-1);
    removido = mp(-1,-1);

    for (int i = 0; i < caminho.size()-1; ++i)
    {
        inserido=mp(-1,-1);
        removido.fi = caminho[i];
        removido.se = caminho[i+1];
        // printf("removidos: %d %d\n",removido.fi, removido.se );
        int u1 = _dfs(_dfs(removido.fi));
        // printf("u1, d1: %d %d\n",u1,dist[u1] );
        while (dist[u1] > d/2) u1= pai[u1];
        int u2 = _dfs(_dfs(removido.se));
        // printf("u2, d2:%d %d\n",u2,dist[u2] );
        while (dist[u2] > d/2) u2= pai[u2];
        inserido=mp(u1,u2);
        // printf("centros: %d %d\n",u1, u2 );
        int v = _dfs(_dfs(0));
        if (dist[v] <= minDiam)
        {
            minDiam = dist[v];
            melhorInsere = inserido;
            melhorRemove = removido;
        }
        // printf("%d\n",dist[v] );



    }
    removido = melhorRemove;
    inserido = melhorInsere;

    return minDiam;
    // printf("%d %d %d\n", u,v, dist[v]);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    int count =1;
    cin >> t;
    while(t--)
    {
        for (int i = 0; i < tree.size(); ++i)
        {
            tree[i].clear();
        }
        tree.clear();
        int n;
        cin >> n;
        // if (count==2)
        // printf("%d\n",n );
        for (int i = 0; i < n; ++i)
            tree.emplace_back();
        for (int i = 0; i < n-1; ++i)
        {
            int a,b;
            cin >> a >> b;
        // if (count==2)
        //     printf("%d %d\n",a,b );
            a--;b--;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        // if (count==2)
        {
            printf("%d\n", achaCentro());
            pii tmp = removido;
            removido.fi = max(tmp.fi, tmp.se);
            removido.se = min(tmp.fi, tmp.se);
            tmp = inserido;
            inserido.fi = max(tmp.fi, tmp.se);
            inserido.se = min(tmp.fi, tmp.se);
            printf("%d %d\n",removido.fi+1, removido.se+1 );
            printf("%d %d\n",inserido.fi+1, inserido.se+1 );
            
        }
        count++;
        // for (int i = 0; i < tree.size(); ++i)
        // {
        //     printf("%d:\n",i );
        //     for (auto v: tree[i])
        //         printf("%d ",v );
        //     printf("\n");
        // }
        // printf("\n");
    }
  
    return 0;
}
