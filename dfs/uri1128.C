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
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int ruas[2123][2123];
int alcanca[2123][2123];
int n,m;
int dfs(int v, int root)
{
	// cout << "entrou " << v << " " <<root <<endl;
	if (alcanca[root][v])
	{
		// cout << "return " << v << " " <<root <<endl;
		return 0;
	}
	alcanca[root][v]  = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (ruas[v][i])
		{
			// cout << root << " alcanca " << i << endl;
			dfs(i,root);
			// alcanca[root][i] = 1;
		}		
	}
	return 0;
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	cin >> n >> m;
 	while (n != 0 && m != 0)
 	{
 		for (int i = 0; i <= n; ++i)
	 	{
	 		for (int j = 0; j <= n; ++j)
	 		{
	 			ruas[i][j] = 0;
	 			alcanca[i][j] = 0;
	 		}
	 	}
	 	for (int i = 0; i < m; ++i)
	 	{
	 		int v,w,p;
	 		cin >> v >> w >> p;
 			ruas[v][w] = 1;
 			// alcanca[v][w]=1;
	 		if (p == 2){
	 			ruas[w][v] = 1;
	 			// alcanca[w][v]=1;
	 		}
 		}
 		int ans = 1;
 		for (int i = 1; i <= n; ++i)
 		{
 			dfs(i,i);
 			for (int j = 1; j <= n; ++j)
 			{
 				if (i != j && !alcanca[i][j])
 				{
 					// cout << i << " " << j<<endl;
 					ans = 0;
 				}
 			}
 		}
 		cout << ans << endl;
 		cin >> n >> m;
 	}
 	

  
	return 0;
}
