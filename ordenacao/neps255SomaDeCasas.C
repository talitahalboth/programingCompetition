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

int c[100010];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	cin >> n;
 	map <int,int> m;
 	for (int i = 0; i < n; ++i)
 	{
 		cin >> c[i];
 		m[c[i]]=1;
 	}
 	int k;
 	cin >> k;
 	int missing = 0;
 	pii par;
 	for (int i = 0; i < n; ++i)
 	{
 		missing = k-c[i];
 		if (m.count(missing) > 0)
 		{
 			par = mp (c[i],missing);
 			break;
 		}
 	}
 	cout << par.fi << " " << par.se <<endl;
  
	return 0;
}
