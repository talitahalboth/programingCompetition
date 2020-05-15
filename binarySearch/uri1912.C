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
#define EPS 1e-4

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


vector <ll> tiras;

long double bb(ll n, ll a, ll maxHeight)
{
	long double sup = maxHeight;
	long double inf = 0;
	long double mid;
	while (inf < sup)
	{
		// cout << inf << " " << sup << endl;
		mid = (inf + sup) / 2.0;
		long double areaCortada = 0;
		for (int i = 0; i < n; ++i)
		{
			if (tiras[i] <= mid)
				break;

			areaCortada+= (long double)tiras[i] - mid;
		}
		// cout << areaCortada << endl;
		if (fabs(areaCortada - double(a)) < EPS)
			 return mid;
		if (areaCortada > a)
			inf = mid;
		else 
			sup = mid ;
	}
	return -1;

}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll n,a;
 	cin >> n >> a;
 	while (n != 0 && a != 0)  
 	{
 		tiras.clear();
 		ll area = 0;
 		ll max = 0;
 		for (ll i = 0; i < n; ++i)
 		{
 			ll x;
 			cin >>x;
 			tiras.pb(x);
 			area+=x;
 			if (x > max)
 				max = x;
 		}
 		// cout << area << " " << a << endl;
 		if (area == a)
 			printf(":D\n");
 		else if (area < a)
 			printf("-.-\n");
 		else
 		{
 			sort (all(tiras));
 			reverse(all(tiras));
 			printf("%.4Lf\n",bb(n,a,max) );

 		}

 		cin >> n >> a;
 	}
	return 0;
}
