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

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector <pll> buildings;
ll calc(ll height)
{
	ll result = 0;
	for (int i = 0; i < buildings.size() ; ++i)
	{
		result += abs(height - buildings[i].fi) * buildings[i].se;
	}
	return result;
}
ll ternarySearch (ll inf, ll sup)
{
	if (inf == sup)
		return sup;
	ll d1 = inf + (sup - inf) / 3;
	ll d2 = sup - (sup - inf) / 3;
	// cout << d1 << " " << d2 << endl;
	ll price1 = calc(d1);
	ll price2 = calc(d2);
	// cout << price1 << " " << price2 << endl;
	if (price1 < price2)
		sup = d2-1;
	else if (price2 < price1)
		inf = d1+1;
	return (ternarySearch(inf,sup));
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int t;
 	cin >> t;
 	for (int i = 0; i < t; ++i)
 	{
 		buildings.clear();
 		int n;
 		cin >> n;
 		for (int i = 0; i < n; ++i)
 		{
 			int h;
 			cin >> h;
 			buildings.pb(mp(h,0)); 			
 		}
 		for (int i = 0; i < n; ++i)
 		{
 			int c;
 			cin >> c;
 			buildings[i].se = c;
 		}
 		sort(all(buildings));
 		ll height = ternarySearch(buildings[0].fi, buildings[buildings.size()-1].fi);
 		cout << calc(height) << endl;

 	}
  
	return 0;
}
