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

int m[20][20];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);

  	int n;
  	cin >> n;
  	for (int i = 0; i < n; ++i)
  		for (int j = 0; j < n; ++j)
  			cin >> m[i][j];
  	int poss = 1;
  	int l,c,d1,d2;
  	d1 = 0;
  	d2 = 0;
  	int s = 0;
  	for (int i = 0; i < n; ++i)
  	{
  		l=0;
  		c=0;
  		for (int j = 0; j < n; ++j)
  		{
  			l += m[i][j];
  			c += m[j][i];
  			if (i == j)
  			{
  				d1+= m[i][j];
  				d2+= m[i][n-1-j];
  			}
  		}
  		if (i == 0)
  			s = l;
  		if (s!= l || c != l)
  		{
  			poss = 0;
  			break;
  		}
  	}
  	if (d1 != s || d2 != s)
  		poss = 0;
  	if (poss)
  		cout << s << endl;
  	else
  		cout << -1 << endl;

	return 0;
}
