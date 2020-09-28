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
#define MAX 11234

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int perm[MAX];
vector<int> g[MAX];
int vis[MAX];
int ccomp[MAX];
int low[MAX];
int p[MAX];
int n,m, ord, root = 0;

bool cmp(int u, int v)
{
	return ccomp[u] > ccomp[v] || (ccomp[u] == ccomp[v] && u < v);
}

void dfs(int u)
{
	int v;
	vis[u] = low[u] = ord++;
	for (int i = 0; i < g[u].size(); ++i)
	{
		v = g[u][i];
		if (!vis[v])
		{
			p[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (u==root)
				ccomp[u]++;
			else if (low[v] >= vis[u]) ccomp[u]++;  

		}
		else if (v!= p[u])
			low[u] = min(low[u], vis[v]);
	}
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	while (scanf("%d %d", &n, &m), n)
 	{
 		for (int i = 0; i <= n; ++i)

 			g[i].clear();
 		int x,y;
 		while(scanf("%d %d", &x, &y), x>=0 )
 		{ 
 			g[x].pb(y);
 			g[y].pb(x);
 		}
 		// caso grafo seja desconexo
 		memset(vis,0, sizeof (vis));
 		// for (int i = 0; i < n; ++i)
 		// {
 		// 	if (!vis[i]) {root=i; dfs(i) };
 		// }
 		for (int i = 0; i < n; ++i)
 			ccomp[i]=1;
 		// numero de componentes na raiz eh o num de filhos
 		// p[0]=-1;
 		ccomp[0]=0;
 		ord = 1;
 		dfs(0);
 		for (int i = 0; i < n; ++i)
 			perm[i] =i;
 		sort(perm, perm+n, cmp);
 		for (int i = 0; i < n && i < m; ++i)
 		{
 			printf("%d %d\n", perm[i], ccomp[perm[i]]);
 		}
 		printf("\n");


 	}
  
	return 0;
}
