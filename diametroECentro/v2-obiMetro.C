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
// vector<vector<int>> circulo;
int pai[2][112345];
int dist[2][112345];
void dfs(int u, int p, int d, int estacao)
{
    if (dist[estacao][u]!=-1)
        return;
    dist[estacao][u] = d;
    pai[estacao][u] = p;
    for (auto v: estacoes[estacao][u])
        dfs(v,u,d+1,estacao);
}
int d;
int _dfs(int u, int estacao)
{
    memset(pai[estacao], -1, sizeof pai[estacao]);
    memset(dist[estacao], -1, sizeof dist[estacao]);
    dfs(u,-1,0,estacao);

    int umax=0;
    for (int i = 0; i < estacoes[estacao].size(); ++i)
    {
        if (dist[estacao][i] > dist[estacao][umax]) umax = i;
    }
    d = dist[estacao][umax];
    return umax;


}

int achaCentro(int estacao)
{
    int u = _dfs(_dfs(0,estacao), estacao);
    while (dist[estacao][u] > d/2) u= pai[estacao][u];
    return u;
    // printf("%d %d %d\n", u,v, dist[estacao][v]);
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
