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

vector <int> bolas;
int possiveis[100];
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);

  	int n, b;
  	cin >> n >> b;
  	while (n!= 0 && b != 0)
  	{
  		for (int i = 0; i <=n; ++i)
  		{
  			possiveis[i]=0;
  		}
  		bolas.clear();
  		for (int i = 0; i < b; ++i)
  	  	{
  	  		int x;
  	  		cin >> x;
  	  		bolas.pb(x);
  	  	}
  	  	for (int i = 0; i < b; ++i)
  	  	{
  	  		for (int j = i+1; j < b; ++j)
  	  		{
  	  			possiveis[abs(bolas[i]-bolas[j])]=1;
  	  		}
  	  	}
  	  	int poss = 1;
  	  	for (int i = 1; i <= n; ++i)
  	  	{
  	  		if (!possiveis[i] )
  	  			poss = 0;
  	  	}
  	  	cout << (poss?"Y":"N") << endl;
  	  	cin >> n >> b;
  	}
	return 0;
}
