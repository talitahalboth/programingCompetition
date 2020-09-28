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
#define MAX 112
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;


int friends[112][112];
vector<pii> friendsTimes[112];
vector<pii> houseTimes[112];
queue<int> prefMan[MAX];
int prefWoman[MAX][MAX];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	cin >> n;
 	for (int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < n; ++j)
 		{
 			int t;
 			cin >> t;
 			friends[i][j];
 			friendsTimes[i].pb(mp(t,j));
 			houseTimes[j].pb(mp(t,i));
 		}
 	}

 	for (int i = 0; i < n; ++i)
 	{
 		sort(all(friendsTimes[i]));
 		sort(all(houseTimes[i]));
 		reverse(all(houseTimes[i] ));
 		for (int j = 0; j < n; ++j)
 		{
 			prefWoman[i][friendsTimes[i][j].se] = j;
 			prefMan[i].push(houseTimes[i][j].se);
 		}
 	}
 	queue <int> rejected;
 	for (int i = 0; i < n; ++i)
 		rejected.push(i);
 	int tentativeProposal[MAX];
 	for (int i = 0; i < MAX; ++i)
 		tentativeProposal[i]=-1;
 	while (! rejected.empty())
 	{
 		int womanIn;
 		int manIn = rejected.front();
 		womanIn = prefMan[manIn].front();
			prefMan[manIn].pop();
 		if (tentativeProposal[womanIn]==-1)
 		{
 			rejected.pop();
 			tentativeProposal[womanIn] = manIn;
 		}
 		if(prefWoman[womanIn][manIn] < prefWoman[womanIn][tentativeProposal[womanIn]])
 		{
 			rejected.pop();
 			rejected.push(tentativeProposal[womanIn]);
 			tentativeProposal[womanIn] = manIn;
 		}
 	}
 	for (int i = 0; i < n; ++i)
 	{ 
 		printf("%d ",tentativeProposal[i]+1 );
 	}
 	printf("\n");
  
	return 0;
}
