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
#define N 11234
using namespace std;

ll n,D;
vector<vector <int>> adj;
// ll pesos[N][N];
vector<int> par[N];
vector<vector <int>> pesos;
ll depth[N];
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

ll visitados[N];
ll distancias[N];
void bfs()
{
    memset(depth, 0, sizeof depth);
    memset(visitados, 0, sizeof visitados);
    queue<int> fila;
    visitados[0] = 1;
    fila.push(0);
    distancias[0]=0;
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
                distancias[v] = distancias[u] + pesos[u][i];
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
    return distancias[i]+distancias[j]- 2*distancias[lca(i,j)];
}
ll findKth(ll i, ll j, ll k)
{
    if (k==1) return i+1;
    ll lcaNode = lca(i,j);
    ll disti = depth[i] - depth[lcaNode];
    ll distj = depth[j] - depth[lcaNode];
    if (disti+1 >= k)
        return (walk (i, k-1)+1);
    ll tmp = k - (disti+1);
    tmp = distj - tmp;
    // printf("tmp: %lld\n",tmp );
    if (!tmp) 
        return j+1;
    return (walk(j,tmp)+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int casos;
    cin >> casos;
    while(casos--)
    {
        cin >> n;
        for (ll i = 0; i < adj.size(); ++i)
        {
            pesos[i].clear();
            adj[i].clear();
        }
        pesos.clear();
        pesos.resize(n);
        adj.clear();
        adj.resize(n);
        // memset(pesos, 0, sizeof pesos);

        for (ll k = 0; k < n-1; ++k)
        {
            ll i,j,c;
            cin >> i >> j >> c;
            i--;j--;
            adj[i].pb(j);
            adj[j].pb(i);
            pesos[i].pb(c);
            pesos[j].pb(c);
            // pesos[i][j]=c;
            // pesos[j][i]=c;
        }
        D = highestOneBit(n)-1;
        for (ll i = 0; i < D+1; ++i)
            par[i].assign(n, -1);
        bfs();
        binaryliftTable();
        string str;
        while(cin >> str, str[1]!='O')
        {
            if (str[0] == 'D')
            {
                int a,b;
                cin >> a >> b;
                a--;b--;
                printf("%lld\n",dist(a,b) );
            }
            else
            {
                int a,b,c;
                cin >> a >> b >> c;
                a--;b--;
                printf("%lld\n",findKth(a,b,c) );
            }
        }
        printf("\n");
        // ll res=0;
        // for (ll i = 1; i <= n; ++i)
        //     for (ll j = i+i; j <= n; j+=i)
        //         res+=dist(i-1, j-1)+1;
        // printf("%lld\n",res );

    }
  
    return 0;
}
