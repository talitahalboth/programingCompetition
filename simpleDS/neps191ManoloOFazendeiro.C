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

int m[100][100];
int regiao[100][4];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	cin >> n;
 	for (int i = 1; i <= n; ++i)
 	{
 		for (int j = 1; j <= n; ++j)
 		{
 			cin >> m[i][j];
 		}
 	}
 	int q;
 	cin >> q;
 	int ans = 0;
 	for (int i = 0; i < q; ++i)
 	{
 		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for (int j = a; j <=c; ++j)
		{
			for (int k = b; k <= d; ++k)
			{
				ans+=m[j][k];
				m[j][k]=0;
				
			}
		}

 	}

 	cout << ans << endl;
  
	return 0;
}
