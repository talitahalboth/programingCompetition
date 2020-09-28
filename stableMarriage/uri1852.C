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
#define MAX 212

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

map <string, int> child, wolf;
map <int, string> childByInd, wolfByInd;

queue<int> prefChild[MAX];
int prefWolf[MAX][MAX];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
	 	int n;
	 	cin >> n;
	 	for (int i = 0; i < n; ++i)
 		{	
	 		string ch;
	 		cin >> ch;
	 		child[ch]=i;
	 		childByInd[i]=ch;
	 		for (int j = 0; j < n; ++j)
	 		{
	 			string w;
	 			cin >> w;
	 			if (i==0)
	 			{
	 				wolf[w]=j;
	 				wolfByInd[j] = w;
	 			}
	 			prefChild[i].push(wolf[w]);
	 		}
	 	}
	 	for (int i = 0; i < n; ++i)
	 	{
	 		string w;
	 		cin >> w;
	 		int indWolf = wolf[w]; 
	 		for (int j = 0; j < n; ++j)
	 		{
	 			string ch;
	 			cin >> ch;
	 			int indCh = child[ch];
	 			prefWolf[indWolf][indCh] = j;
	 		}
	 		prefWolf[indWolf][n]=n;
	 	}

	 	queue <int> rejected;
	 	for (int i = 0; i < n; ++i)
	 		rejected.push(i);
	 	int tentativeProposal[MAX];
	 	for (int i = 0; i < MAX; ++i)
	 		tentativeProposal[i]=-1;
	 	while (! rejected.empty())
	 	{
	 		int wolfIn;
	 		int childIn = rejected.front();
	 		wolfIn = prefChild[childIn].front();
 			prefChild[childIn].pop();
	 		if (tentativeProposal[wolfIn]==-1)
	 		{

	 			rejected.pop();
	 			tentativeProposal[wolfIn] = childIn;
	 		}
	 		if(prefWolf[wolfIn][childIn] < prefWolf[wolfIn][tentativeProposal[wolfIn]])
	 		{
	 			rejected.pop();
	 			rejected.push(tentativeProposal[wolfIn]);
	 			tentativeProposal[wolfIn] = childIn;
	 		}
	 	}
	 	vector <pii> ans;
	 	for (int i = 0; i < n; ++i)
	 		ans.pb(mp(tentativeProposal[i], i));
	 	sort(all(ans));
	 	for (int i = 0; i < n; ++i)
	 		cout << childByInd[ans[i].fi] << " " <<wolfByInd[ans[i].se] << endl;
  
	return 0;
}
