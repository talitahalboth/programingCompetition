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
#define N 112345
ll n,D;
vector<vector <int>> adj;
vector<int> par[N];
vector<vector <int>> pesos;
vector<int> depthsArray[N];
ll depth[N];
int child[N];
int bigDepth=0;
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
ll cnt[N];
ll newNumber[N];
// ll bfs(ll start, ll treeStart)
// {
//     queue<int> fila;
//     visitados[start] = 1;
//     fila.push(start);
//     cnt[start] = 0;
//     newNumber[start] = treeStart++;
//     while (!fila.empty())
//     {
//         ll u = fila.front();
//         fila.pop();
//         for (ll i = 0; i < adj[u].size(); i++)
//         {
//             ll v = adj[u][i];
//             if (!visitados[v])
//             {
//                 cnt[u]++;
//                 newNumber[v] = treeStart++;
//                 visitados[v]=1;
//                 fila.push(v);
//                 par[0][v] = u; 
//                 depth[v] = depth[u]+1;
//                 ll parent = par[0][u];
//                 while (parent != -1)
//                 {
//                     cnt[parent]++;
//                     parent = par[0][parent];
//                 }
//             }
//         }
//     }
//     return treeStart;
// }

ll dfs(ll u, ll treeNum)
{
    visitados[u] = 1;
    newNumber[u] = treeNum;
    depthsArray[depth[u]].pb(newNumber[u]);
    for (ll i = 0; i < adj[u].size(); ++i)
    {
        ll v = adj[u][i];
        if (!visitados[v])
        {
            
            depth[v] = depth[u]+1;
            par[0][v] = u;
            cnt[u]++;
            // ll parent = u;
            // while (parent != -1)
            // {
            //     cnt[parent]++;
            //     parent = par[0][parent];
            // }
            treeNum = dfs(v, treeNum+1);
        }
    }
    int parent = par[0][u];
    if (parent!=-1)
        cnt[parent]+=cnt[u];
    return treeNum;
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

ll bbMenor(ll depth, ll v)
{
    // printf("v,cnt:%lld %lld\n",v,cnt[v] );
    if (cnt[v]==0)
        return -1;
    ll sup = depthsArray[depth].size()-1;
    ll inf = -1;
    ll elem = newNumber[v]+1;

    // printf("elem ini: %lld\n",elem );
    ll mid;
    while (sup > inf)
    {
        mid = inf + (sup-inf+1)/2;
        if (depthsArray[depth][mid] < elem)
            inf = mid;
        else if (depthsArray[depth][mid] >= elem)
            sup = mid-1; 
    }
    return sup;
}
ll bbMaior(ll depth, ll v)
{
    // printf("v,cnt:%lld %lld\n",v,cnt[v] );
    if (cnt[v]==0)
        return -1;
    ll sup = depthsArray[depth].size();
    ll inf = 0;
    ll elem = newNumber[v]+cnt[v];
    // printf("elem fim: %lld\n",elem );

    ll mid;
    while (sup > inf)
    {
        // printf("%lld %lld\n", sup, inf);
        mid = inf + (sup-inf)/2;
        if (depthsArray[depth][mid] <= elem)
            inf = mid+1;
        else if (depthsArray[depth][mid] > elem)
            sup = mid; 
    }
    return inf;
}

int main(){
    vector<int> roots;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    adj.resize(n);
    for (ll i = 0; i < n; ++i)
    {
        ll r;
        cin >> r;
        if (r!=0)
        {
            r--;
            adj[i].pb(r);
            adj[r].pb(i);
        }
        else
            roots.pb(i);
        
    }
    D = highestOneBit(n)-1;
    for (ll i = 0; i < D+1; ++i)
        par[i].assign(n, -1);
    memset(depth, 0, sizeof depth);
    memset(visitados, 0, sizeof visitados);
    ll countTrees=0;
    for (auto i: roots)
    {
        if (!visitados[i])
        {
            countTrees = dfs(i, countTrees)+1;
        }
    }
    // for (ll i = 0; i < n; ++i)
    // {
    //     printf("%lld ",cnt[i] );
    //     printf("%lld: ",i+1 );
    //     for (auto v: adj[i])
    //         printf("%lld ",v+1 );
    //     printf("\n");
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     ll u = i;
    //     ll parent = par[0][u];
    //     while (parent != -1)
    //     {
    //         printf("u, par: %lld, %lld: %lld\n",u+1,parent+1, cnt[u] );
    //         cnt[parent]+=cnt[u];
    //         u = parent;
    //         parent = par[0][parent];

    //     }
    //         printf("u, par: %lld, %lld: %lld\n",u+1,parent+1, cnt[u] );
    // }
    
    // for (ll i = 0; i < n; ++i)
    // {
    //     printf("%lld %lld %lld\n", i,newNumber[i],cnt[i] );

    // }
    // for (ll i = 0; i < n; ++i)
    // {
    //     printf("depth %lld: ",i );
    //     for (ll j = 0; j < depthsArray[i].size(); ++j)
    //     {
    //         printf("%lld ",depthsArray[i][j] );
    //     }
    //     printf("\n");
    // }
    binaryliftTable();
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i)
    {
        ll v,p;
        cin >> v >> p;
        ll ancestor = walk(v-1, p);
        if (ancestor == -1)
            printf("0 ");
        else
        {
            // printf("ancestor: %lld\n",ancestor );
            //acha indice do primeiro elemento maior que oq queremos
            ll s = bbMaior(depth[v-1], ancestor);
            // if (s!= -1)
            {
                ll e = bbMenor(depth[v-1], ancestor);
                s--;
                e++;
                // printf("%lld %lld %lld\n",depth[v-1], s,e );
                ll result =  s - e;
                printf("%lld ",result );
                
            }

        }

    }
    printf("\n");

  
    return 0;
}
