#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll n;
ll pilhas[100010];

ll bb(ll worm)
{
	ll sup = n;
	ll inf = 1;
	while (inf < sup)
	{
		ll mid = inf + (sup - inf) / 2;
		// cout << inf << " " << mid << " " << sup << endl;
		if (pilhas[mid] >= worm && pilhas[mid-1]+1 <= worm )
			return mid;
		if (pilhas[mid] < worm)		
			inf = mid+1;
		else
			sup = mid;

	}
	return inf;
}
int main()
{
	scanf ("%lld", &n);
	pilhas[0]=0;
	for (ll i = 1; i <= n; ++i)
	{
		ll x;
		scanf ("%lld", &x);
		pilhas[i] = pilhas[i-1] + x;
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; ++i)
	{
		ll q;
		scanf ("%lld", &q);
		cout << bb(q) << endl;

	}

	return 0;
}