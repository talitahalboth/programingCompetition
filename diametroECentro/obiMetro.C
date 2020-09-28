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


int n,m;

vector<vector<int>> estacoes[2];
int pai[2][112345];
int dist[2][112345];

void dfs(int u, int p, int estacao)
{
    for (auto v: estacoes[estacao][u])
    {
        if (v==p) continue;
        dist[estacao][v]=dist[estacao][u]+1;
        pai[estacao][v]=u;
        dfs(v,u,estacao);
    }
}

void _dfs(int u, int estacao)
{
    dist[estacao][u]=0;
    dfs(u,-1,estacao);
}

int achaCentro(int estacao)
{
    int sz = estacao==0? n: m;
    _dfs(0,estacao);
    int u=0;
    for (int i = 0; i < sz; ++i)
        if (dist[estacao][i] > dist[estacao][u])
            u = i;
        
    _dfs(u, estacao);
    int v=0;
    for (int i = 0; i < sz; ++i)
        if (dist[estacao][i] > dist[estacao][v])
            v = i;

    int d = dist[estacao][v];
    while (dist[estacao][v] > d/2) v= pai[estacao][v];
    return v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        estacoes[0].emplace_back();
    for (int i = 0; i < n-1; ++i)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        estacoes[0][a].pb(b);
        estacoes[0][b].pb(a);
    }
    for (int i = 0; i < m; ++i)
        estacoes[1].emplace_back();
    for (int i = 0; i < m-1; ++i)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        estacoes[1][a].pb(b);
        estacoes[1][b].pb(a);
    }
    printf("%d ", achaCentro(0)+1); 
    printf("%d\n", achaCentro(1)+1); 


  
    return 0;
}
