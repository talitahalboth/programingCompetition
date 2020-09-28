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

ll matriz[100][100];

ll brancosLinha[100];
ll brancosColuna[100];
ll powers[100];
ll powerOfTwo (ll n)
{
	if (n == 0)
		return 1;
	if (powers[n]!=0)
		return powers[n];
	powers[n] = 2*powerOfTwo(n-1);
	return powers[n];

}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll n,m;
 	cin >> n >> m;
 	for (ll i = 0; i < n; ++i)
 	{
 		for (ll j = 0; j < m; ++j)
 		{
 			cin >> matriz[i][j];
 			brancosLinha[i]+=matriz[i][j];
 			brancosColuna[j]+=matriz[i][j];

 		}
 	}
 	ll ans = 0;

 	ans = n*m;
	ll a,b,c,d;
	a=b=c=d=0;
 	for (ll i = 0; i < n; ++i)
 	{
 		a=c=0;
 		if (brancosLinha[i]>1)
 			a = powerOfTwo(brancosLinha[i]) - 1 - brancosLinha[i];
 		if (m-brancosLinha[i]>1)
 			c = powerOfTwo(m-brancosLinha[i]) - 1 - (m-brancosLinha[i]);
 		ans+=a+c;
 	}
 	for (ll i = 0; i < m; ++i)
 	{
 		b=d=0;
 		if (brancosColuna[i]>1)
 			b = powerOfTwo(brancosColuna[i]) - 1 - brancosColuna[i];
 		if (n-brancosColuna[i]>1)
 			d = powerOfTwo(n-brancosColuna[i]) - 1 - (n-brancosColuna[i]);
 		ans+=b+d;
 	}	
  	cout << ans << endl;
	return 0;
}
