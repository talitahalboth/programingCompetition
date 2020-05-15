#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll elem[200000];
ll n;
ll binarySearch (ll x)
{
	ll sup = n-1;
	ll inf = 0;
	while (inf < sup)
	{
		ll mid = (sup+inf)/2;
		if (elem[mid] < x)
			inf = mid + 1;
		else if (elem[mid] > x)
			sup = mid - 1;
		else
			sup = mid;
	}
	if (elem[inf]== x)
		return inf;
	return -1;

}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll q;
 	scanf ("%lld %lld", &n, &q);
 	for (ll i = 0; i < n; ++i)
 		scanf ("%lld", &elem[i]);
 	for (ll i = 0; i < q; ++i)
 	{
 		ll query;
 		scanf ("%lld", &query);
 		printf("%lld\n", binarySearch(query));
 	}
 	
 	// cout << elem[sup]<<	endl;

  
	return 0;
}

