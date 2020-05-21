#include <bits/stdc++.h>
#define fi first
#define se second
// #define pb push_back
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

int n,m;
int paths[11234][11234];
int dist[11234];
int visited[11234];
vector <pii> shortestPaths;
int parent[11234];

void saveShortestPath(int v, int par)
{
	while (par != -1)
	{
		shortestPaths.push_back(mp(par,v));
		v = par;
		par = parent[v];
	}
}


int dijkstra(int src, int dst)
{
	priority_queue<int, vector<int>, greater<int> > fila;
	fila.push(src);
	dist[src]=0;
	parent[src] = -1;
	visited[src] = 1;
	while (!fila.empty())
	{
		int u = fila.top();
		fila.pop();
		for (int i = 0; i < n; ++i)
		{
			if (paths[u][i])
			{
				if ( i == dst)
				{
					if (dist[i] == dist[u]+paths[u][i])
					{
						// se achou outro caminho com o msm tamanho, adiciona os vértices
						saveShortestPath(i,u);
						continue;
					}

				}
				if (!visited[i] || dist[i] > dist[u]+paths[u][i])
				{
					dist[i] = dist[u]+paths[u][i];
					fila.push(i);
					parent[i] = u;
					visited[i] = 1;
					if (i == dst)
					{
						// se achou um caminho com tamanho menor, limpa os caminhos
						shortestPaths.clear();
						saveShortestPath(dst, u);
					}
				}
				
			}
		}
	}

}
void dijkstra2 (int src, int dst)
{
	priority_queue<int, vector<int>, greater<int> > fila;
	fila.push(src);
	dist[src]=0;
	parent[src] = -1;
	visited[src] = 1;
	while (!fila.empty())
	{
		int u = fila.top();
		fila.pop();
		for (int i = 0; i < n; ++i)
		{
			if (paths[u][i])
			{
				if (!visited[i] || dist[i] > dist[u] + paths[u][i])
				{
					visited[i]=1;
					dist[i] = dist[u] + paths[u][i];
					fila.push(i);
				}
								
			}
		}
	}

}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0); 	
  	cin >> n >> m;
  	while (n && m)
  	{
  		ll s,d;
  		cin >> s >> d;

		shortestPaths.clear();
  		for (int i = 0; i < n; ++i)
  		{
  			parent[i]=0;
  			visited[i] = 0;
  			dist[i]=0;
  			memset(paths[i], 0, sizeof(paths[i]));
  		}

  		for (ll i = 0; i < m; ++i)
  		{
  			ll u,v,p;
  			cin >> u >> v >> p;
  			paths[u][v] = p;
  		}

  		dijkstra(s,d);
  		for (int i = 0; i < shortestPaths.size(); ++i)
  		{
  			paths[shortestPaths[i].fi][shortestPaths[i].se] = 0;
  		}
  		memset(visited,0,sizeof(visited));
  		memset(dist,0,sizeof(dist));
  		dijkstra2(s,d);
  		if (!visited[d]) printf("-1\n");
  		else printf("%d\n",dist[d] );
  		cin >> n >> m;
  	}
	return 0;
}

