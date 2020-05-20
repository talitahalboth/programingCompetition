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

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll n;
ll s,t,c;
ll routers[200][200];
ll residue[200][200];
ll visited[200];
ll parent[200];
ll bfs(ll src, ll dst)
{
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	queue <ll> fila;
	fila.push(src);
	visited[src] = 1;
	parent[src] = -1;
	while (!fila.empty())
	{
		ll v = fila.front();
		fila.pop();
		for (ll i = 1; i <= n; ++i)
		{
			if (residue[v][i])
			{
				if (!visited[i])
				{
					parent[i] = v;
					visited[i] = 1;
					fila.push(i);
				}
				if (i == dst)
					return 1;
			}
		}
	}
	if (visited[dst]) return 1;
	return 0;
}
ll fordFulkerson (ll source, ll sink)
{
	ll maxFlow = 0;
	for (ll i = 1; i <= n; ++i)
	{
		for (ll j = 1; j <= n; ++j)
		{
			residue[i][j] = routers[i][j];
		}
	}
	while (bfs(source, sink))
	{
		ll v = sink;
		ll flow = iinf;
		while (v != source)
		{
			ll u = parent[v];
			if (residue[u][v] < flow)
				flow = residue[parent[v]][v];
			v = u;
		}
		v = sink;
		while (v != source)
		{
			ll u = parent[v];
			residue[u][v] -= flow;
			residue[v][u] += flow;
			v = u;
		}
		maxFlow+=flow;
	}
	return maxFlow;
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	cin >> n;
 	ll count = 1;
 	while (n)
 	{
 		cin >> s >> t >> c;
 		for (ll i = 0; i <= n; ++i)
 		{
 			memset(routers[i], 0, sizeof(routers[i]));
 		}
 		for (ll i = 0; i < c; ++i)
 		{
 			ll u,v,w;
 			cin >> u >> v >> w;
 			routers[u][v] += w;
 			routers[v][u] += w;
 			
 		}
 		printf("Network %d\n",count );
 		printf("The bandwidth is %lld.\n",fordFulkerson(s,t)); 
 		printf("\n");
 		count++;
 		cin >> n;
 	}
  	
	return 0;
}
