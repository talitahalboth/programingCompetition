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
#define MAX 112

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
int ans;
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
		{
			low[u] = min(low[u], vis[v]);
		}
	}
	if (ccomp[u] > 1)
		ans++;


}
map <string, int> locations;
map <int, string> locationsByInd;
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	int contaCasos =1;
 	while (cin >> n, n)
 	{
 		ans=0;
 		locations.clear();
 		locationsByInd.clear();
 		for (int i = 0; i <= n; ++i)
 			g[i].clear();
 		for (int i = 0; i < n; ++i)
 		{
 			string s;
 			cin >> s;
 			locations[s]=i;
 			locationsByInd[i]=s;
 		}
 		int r;
 		cin >> r;
 		for (int i = 0; i < r; ++i)
 		{
 			string s1,s2;
 			cin >> s1 >> s2;
 			int u,v;
 			u = locations[s1];
 			v = locations[s2];
 			g[u].pb(v);
 			g[v].pb(u);
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
 		if (contaCasos>1)
 			cout << endl;
 		cout << "City map #"<< contaCasos<<": "<<ans<<" camera(s) found"<<endl;
 		vector<string> saida;
 		for (int i = 0; i < n; ++i)
 		{
 			if (ccomp[i] > 1)
 				saida.pb(locationsByInd[i]);
 		}
 		sort(all(saida));
 		for (int i = 0; i < saida.size(); ++i)
 			cout << saida[i] << endl;
 		contaCasos++;

 	}
  
	return 0;
}
