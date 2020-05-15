#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector <string> nomes;
vector <ll> strength;
ll bb()
{
	ll sup = nomes.size();
	ll inf = 0;
	while (sup > inf)
	{
		ll mid = inf + (sup-inf)/2;
		ll sumA=0;
		ll count = mid;
		for (ll i = 0; i < mid; ++i)
		{
			sumA+= strength[i]*count;
			count--;
		}
		count = 1;
		ll sumB = 0;
		for (ll i = mid; i < nomes.size(); ++i)
		{
			sumB+=strength[i]*count;
			count++;
		}
		if (sumA < sumB)
			inf = mid+1;
		else if (sumB < sumA)
			sup = mid-1;
		else
			return mid;
	}
	ll sumA=0;
	ll count = sup;
	for (ll i = 0; i < sup; ++i)
	{
		sumA+= strength[i]*count;
		count--;
	}
	count = 1;
	ll sumB = 0;
	for (ll i = sup; i < nomes.size(); ++i)
	{
		sumB+=strength[i]*count;
		count++;
	}
	if (sumA == sumB)
		return sup;
	return -1;


}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll n;
 	cin >> n;
 	while (n != 0)
 	{
 		nomes.clear();
 		strength.clear();
 		for (ll i = 0; i < n; ++i)
 		{
 			string str;
 			cin >> str;
 			ll sum = 0;
 			for (ll i = 0; i < str.size(); ++i)
 			{
 				sum+=str[i];
 			}
 			strength.pb(sum);
 			nomes.pb(str);
 		}
 		ll ans = bb();
 		if (ans != -1)
 			cout << nomes[ans-1] << endl;
 		else
 			cout << "Impossibilidade de empate." << endl;
 		// cout << bb() << endl;

 		cin >> n;
 		
 	}
  
	return 0;
}
