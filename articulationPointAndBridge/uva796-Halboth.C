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
#define MAX 112345
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int perm[MAX];
vector<int> g[MAX];
// inicializa com 0
int vis[MAX];
// inicializa com 1 exceto raiz
int ccomp[MAX];
int low[MAX];
int p[MAX];
int n,m, ord, root = 0;
vector<pii> ans;
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
			if (low[v] > vis[u]) 
			{
				// printf("%d %d\n",u,v );
				ans.pb(mp(min(u,v), max(u,v)));
			}

		}
		else if (v!= p[u])
		{
			low[u] = min(low[u], vis[v]);
		}
	}


}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	while (scanf ("%d", &n)!=EOF)
 	{
 		ans.clear();
 		for (int i = 0; i < MAX; ++i)
 		{
 			g[i].clear();
 		}
 		for (int i = 0; i < n; ++i)
 		{
 			int u;
 			scanf("%d", &u);
 			char str[112];
 			scanf("%s", str);
 			str[strlen(str)-1]=0;
 			str[0] = '0';
 			int k = atoi(str);
 			// printf("%d\n",k );
 			for (int i = 0; i < k; ++i)
 			{
 				int v;
 				scanf("%d", &v);
 				g[u].pb(v);

 			}
 		}
 		memset(vis, 0, sizeof(vis));
 		memset(p, 0, sizeof(p));
 		for (int i = 0; i < n; ++i)
 			ccomp[i]=1;
 
 		for (int i = 0; i < n; ++i)
 		{
 			if (!vis[i])
 			{
 				root = i;
 				ccomp[i]=0;
 				p[i]=-1;
 				ord=1;
 				dfs(i);
 			}
 		}
 		sort(all(ans));
 		printf("%d critical links\n",ans.size() );
 		for (int i = 0; i < ans.size(); ++i)
 		{
 			printf("%d - %d\n",ans[i].fi,ans[i].se );
 		}
 		printf("\n");
 		
 	}

	return 0;
}