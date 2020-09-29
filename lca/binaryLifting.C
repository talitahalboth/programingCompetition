#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (ll (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (ll (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (ll (X) = (Y)-1;(X) >=0;--(X))
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


ll n,D;
vector<vector <int>> adj;
vector<int> par[212345];
ll depth[212345];
ll highestOneBit(ll n)
{
    if (n==1)
        return 1;
    ll count=0;
    while (n>0)
    {
        n=n/2;
        count++;
    }
    return count;
}

ll visitados[212345];

void bfs()
{
    memset(depth, 0, sizeof depth);
    memset(visitados, 0, sizeof visitados);
    queue<int> fila;
    visitados[0] = 1;
    fila.push(0);
    while (!fila.empty())
    {
        ll u = fila.front();
        fila.pop();
        for (ll i = 0; i < adj[u].size(); i++)
        {
            ll v = adj[u][i];
            if (!visitados[v])
            {
                visitados[v]=1;
                fila.push(v);
                par[0][v] = u; 
                depth[v] = depth[u]+1;
            }
        }
    }
}

void binaryliftTable()
{
    for (ll d = 1; d <= D; ++d)
    {
        for (ll i = 0; i < n; ++i)
        {
            ll mid = par[d-1][i];
            if (mid != -1)
                par[d][i] = par[d-1][mid];
        }
    }
}

// makes jumps from i based on binary value of k
ll walk(ll i, ll k)
{
    for (ll d = 0; d <= D && i != -1; ++d)
        if ( ((1<<d) & k) > 0)
            i = par[d][i];
    return i;
}

// return the first node below the actual lca
ll lca(ll i, ll j)
{
    if (depth[i] > depth[j])
        i = walk(i, depth[i]-depth[j]);
    if (depth[i] < depth[j])
        j = walk(j, depth[j]-depth[i]);
    if (i == j)
        return i;
    for (ll d = D; d >= 0; --d)
    {
        if (par[d][i] != par[d][j])
        {
            i = par[d][i];
            j = par[d][j];
        }
    }
    return par[0][i];
}

ll dist(ll i, ll j)
{
    return depth[i]+depth[j]- 2*depth[lca(i,j)];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for (ll i = 0; i < adj.size(); ++i)
            adj[i].clear();
        adj.clear();
        adj.resize(n);

        for (ll k = 0; k < n-1; ++k)
        {
            ll i,j;
            cin >> i >> j;
            i--;j--;
            adj[i].pb(j);
            adj[j].pb(i);
        }
        D = highestOneBit(n)-1;
        for (ll i = 0; i < D+1; ++i)
            par[i].assign(n, -1);
        bfs();
        binaryliftTable();
        ll res=0;
        for (ll i = 1; i <= n; ++i)
            for (ll j = i+i; j <= n; j+=i)
                res+=dist(i-1, j-1)+1;
        printf("%lld\n",res );

    }
  
    return 0;
}
