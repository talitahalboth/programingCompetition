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
#define llinf (long long)(1e14)
#define N 1123
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;


ll g[N][N];
ll variable[N][N];
vector<pii > variableEdges;
vector <pii> adj[N];

ll n;
ll dist[N];
ll visited[N];

ll dijkstra (ll src, ll dst)
{
    for (ll i = 0; i < n; ++i)
        dist[i] = llinf;
    memset(visited, 0, sizeof visited);
    priority_queue<ll, vector<ll>, greater<ll> > fila;
    fila.push(src);
    dist[src]=0;
    visited[src] = 1;
    while (!fila.empty())
    {
        ll u = fila.top();
        fila.pop();
        for (int i = 0; i < adj[u].size(); ++i)
        {
            ll v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if (w == 0)
                w = g[u][v];

            if (w != 0 && (!visited[v] ||  dist[v] > dist[u] + w))
            {

                visited[v]=1;
                dist[v] = dist[u] + w;
                fila.push(v);
            }
        }
    }
    return dist[dst];
}

ll m,l,s,t;
ll bb1()
{
    ll inf=-1;
    ll sup = variableEdges.size()-1;
    ll ans;
    while(inf <= sup)
    {
        memset(visited, 0, sizeof visited);
        ll mid = (sup+inf)/2;
        for (ll i = 0; i <= mid; ++i)
        {
            ll u = variableEdges[i].fi;
            ll v = variableEdges[i].se;
            g[u][v]=1;
            g[v][u]=1;
        }
        for (ll i = mid+1; i < variableEdges.size(); ++i)
        {
            ll u = variableEdges[i].fi;
            ll v = variableEdges[i].se;
            g[u][v]=llinf;
            g[v][u]=llinf;
        }
        ll res = dijkstra(s,t);
        if (res <= l)
        {
            ans = mid;
            sup = mid-1;
        }
        else
            inf = mid+1;
    }
    return ans;
}
ll result;
ll bb2(ll pos)
{
    ll inf=-1;
    ll sup = (long long)(1e18);
    ll ans;
    for (ll i = 0; i <= pos; ++i)
    {
        ll u = variableEdges[i].fi;
        ll v = variableEdges[i].se;
        g[u][v]=1;
        g[v][u]=1;
    }
    for (ll i = pos+1; i < variableEdges.size(); ++i)
    {
        ll u = variableEdges[i].fi;
        ll v = variableEdges[i].se;
        g[u][v]=llinf;
        g[v][u]=llinf;
    }
    ll u = variableEdges[pos].fi;
    ll v = variableEdges[pos].se;
    while(inf <= sup)
    {
        memset(visited, 0, sizeof visited);

        ll mid = (sup+inf)/2;

        g[u][v]=mid;
        g[v][u]=mid;
        ll res = dijkstra(s,t);
        if (res <= l)
        {
            result = res;
            ans = mid;
            inf = mid+1;
        }
        else
            sup = mid-1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m>>l>>s>>t;
    for (ll i = 0; i < m; ++i)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
        if (!w)
        {
            variableEdges.pb(mp(u,v));
            variable[u][v]=1;
            variable[v][u]=1;
        }
        else
        {
            g[u][v]=w;
            g[v][u]=w;
        }
    }
    for (ll i = 0; i < n; ++i)
        dist[i] = llinf;

    if (dijkstra(s,t) < l)
        printf("NO\n");
    else
    {
        for (ll i = 0; i < variableEdges.size(); ++i)
        {
            ll u = variableEdges[i].fi;
            ll v = variableEdges[i].se;
            g[u][v]=1;
            g[v][u]=1;
        }
        memset(visited, 0, sizeof visited);

        if (dijkstra(s,t) > l)
            printf("NO\n");
        else
        {

            memset(visited, 0, sizeof visited);
            for (ll i = 0; i < n; ++i)
                dist[i] = llinf;

            if (dijkstra(s,t) == l)
            {
                printf("YES\n");
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (i<j)
                        if (g[i][j])
                        {
                            if (g[i][j]==llinf)
                                g[i][j] = (long long)(1e18);
                            printf("%d %d %lld\n",i,j,g[i][j] );
                        }
                    }
                }
                

            }
            else
            {
                printf("YES\n");
                ll lim = bb1();
                ll num = bb2(lim);
                assert(result == l);
                ll u = variableEdges[lim].fi;
                ll v = variableEdges[lim].se;
                g[u][v]=num;
                g[v][u]=num;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (i<j)
                        if (g[i][j])
                        {
                            if (g[i][j]==llinf)
                                g[i][j] = (long long)(1e18);
                            printf("%d %d %lld\n",i,j,g[i][j] );
                        }
                    }
                }
                
                
            }
        }

    }

  
    return 0;
}