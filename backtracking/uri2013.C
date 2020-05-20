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
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll algarismos[20];
ll tentativa[20];
ll tentativaNum[10];
ll findBiggestPossible(ll n, ll lvl)
{
	ll c = n-1;
	while (c >= 0 && tentativa[c] == algarismos[c])
		c--;
	c++;
	if (c <= lvl+1)
		return (algarismos[lvl]);
	return 9;

}
ll backtrack(ll n, ll lvl)
{
	if (lvl == -1)
		return 1;
	if (lvl == n-1)
	{
		for (ll i = algarismos[lvl]; i >= 0; --i)
		{
			tentativa[lvl] = i;
			tentativaNum[i]=1;
			if (backtrack(n,lvl-1)) 
				return (1);
			tentativaNum[i]=0;
		}
	}
	else
	{
		ll i = findBiggestPossible(n,lvl);
		while (i >= 0 && tentativaNum[i] >=2)
			i--;
		if (i < 0)
			return 0;
		else
		{
			for ( ; i >= 0; i--)
			{
				tentativa[lvl] = i;
				if (tentativaNum[i] < 2)
				{
					tentativaNum[i]++;
					if (backtrack(n,lvl-1))
						return 1;
					tentativaNum[i]--;
					tentativa[lvl] =-1;
				}
				
			}
		}

	}
	return 0;
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll u;

 	cin >> u;
 	ll tmp = u;
 	ll count = 0;
 	ll num[10];
 	memset(num, 0, sizeof(num));
 	while (tmp > 0)
 	{
 		algarismos[count] = tmp%10;
 		num[tmp%10]++;
 		tmp /= 10;
 		count++;
 	}
 	memset(tentativa, 0, sizeof(tentativa));
 	memset(tentativaNum, 0, sizeof(tentativaNum));
 	for (ll i = 0; i < count; ++i)
 	{
 		tentativa[i] = -1;
 	}
 	backtrack(count, count-1);
 	while (!tentativa[count])
 		count--;
 	for (ll i = count; i >= 0; --i)
 	{
		printf("%d",tentativa[i] );
 	}
 	printf("\n");
  
	return 0;
}
