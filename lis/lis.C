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
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

vector <int> a;
vector <int> ant;
vector <int> lis;


void dp(int pos)
{
	if (pos == a.size())
		return;
	// length of lis at pos is at least one (itself)
	int longest = 1;
	int longestIndex = -1;
	// test every number before pos
	// see if its possible to extend the sequence
	for (int i = 0; i<=pos-1; ++i)
	{
		// is possible
		if (a[pos] > a[i])
		{
			// and no other index increased the list
			if (longestIndex == -1 )
			{
				//takes this index
				longestIndex = i;
				// increase length of lis
				longest = lis[longestIndex]+1;
			}
			// another index was found, compare new length
			// grater since we only want the first sequence we find
			else if (lis[i]+1 > longest)
			{
				longestIndex = i;
				// increase length of lis
				longest = lis[i]+1;
			}
		}
	}
	// length of lis at this position is the longest we could find
	lis[pos] = longest;
	// set the index of the previous 
	if (longestIndex != -1)
		ant[pos] = longestIndex;
	// goes to next step
	dp(pos+1);
}


int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int x;
 	while (cin >> x )
 	{
 		a.pb(x);
 		lis.pb(0);
 		ant.pb(-1);
 	}
 	// reverse(all(a));
 	dp(0);
 	int maxIndex = 0;
 	for (int i = 0; i < a.size(); ++i)
 	{
 		// only changes max index if its bigger (meaning it'll get the first lis)
 		if (lis[i] > lis[maxIndex])
 			maxIndex = i;
 	}
 	vector <int> ans;
 	ans.pb(maxIndex);
 	int tmp = maxIndex;
 	while (ant[tmp] != -1)
 	{
 		ans.pb(ant[tmp]);
 		tmp = ant[tmp];
 	}
 	printf("%lu\n",ans.size() );
 	// reverse the ans array
 	reverse(all(ans));
 	printf("-\n");
 	for (int i = 0; i < ans.size(); ++i)
 		printf("%d\n",a[ans[i]] );
  	
	return 0;
}