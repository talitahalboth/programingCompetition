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

ll botas[65][2];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);

  	ll n;
  	cin >> n;
  	ll certos = 0;
  	for (ll i = 0; i < 65; ++i)
  	{
  		botas[i][0] = 0;
  		botas[i][1] = 0;
  	}
  	for (ll i = 0; i < n; ++i)
  	{
  		ll m;
  		char l;
  		cin >> m  >> l;
  		if (l == 'D')
  			botas[m][0]++;
  		else
  			botas[m][1]++;
  	}
  	for (ll i = 0; i < 65; ++i)
  	{
  		certos += min(botas[i][0], botas[i][1]);
  	}
  	cout << certos << endl;
	return 0;
}
