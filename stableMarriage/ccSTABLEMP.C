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


#define MAX 512
int n;
//men’s preferentes, store preferences of man i in order 
int a[MAX][MAX];
//women’s preferences, store how much woman i likes man j (0 is the best)
int b[MAX][MAX];
int match[MAX], watch[MAX], single[MAX];

void stableMarriage()
{
	int flag=1;
	for (int m = 0; m < n; ++m)
	{
		single[m]=1;
		match[m]=-1;
	}
	for (int w = 0; w < n; ++w)
	{
		watch[w] = n;
		b[w][n] = n;
	}
	int w;
	while (flag)
	{
		flag=0;
		for (int m = 0; m < n; ++m)
		{
			if (single[m])
			{
				flag=1;
				match[m]++;
				w = a[m][match[m]];
				if (b[w][m] < b[w][watch[w]])
				{
					single[watch[w]]=1;
					watch[w]=m;
					single[m]=0;
				}
			}
		}
	}
}


int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int cases;
 	cin >> cases;
 	while(cases--)
 	{
 		cin >> n;
 		for (int i = 0; i < n; ++i)
 		{
 			int w;
 			cin >> w;
 			for (int j = 0; j < n; ++j)
 			{
	 			int prefW;
	 			cin >> prefW;
	 			b[w-1][prefW-1] = j;
 			}
 		}
 		for (int i = 0; i < n; ++i)
 		{
 			int m;
 			cin >> m;
 			for (int j = 0; j < n; ++j)
 			{
 				int prefM;
 				cin >> prefM;
 				a[m-1][j] = prefM-1;
 			}
 		}

 		stableMarriage();
 		for (int i = 0; i < n; ++i)
 		{
 			printf("%d %d\n",i+1, a[i][match[i]]+1 );
 		}
 	}
	return 0;
}
