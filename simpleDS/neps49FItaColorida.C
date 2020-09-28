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

int distDir[10010];
int distEsq[10010];
int a[10010];
int findDistanceEsq(int v,int n)
{
	if (v == n-1) 
	{
		if (a[v] == -1)
			distEsq[v]=inf;
		else
			distEsq[v]=0;
		return distEsq[v];
	}
	if (a[v] != -1)
	{
		distEsq[v]=0;
		return 0;
	}
	distEsq[v] = 1+findDistanceEsq(v+1,n);
	return distEsq[v];
}

int findDistanceDir(int v)
{
	if (v == 0) 
	{
		if (a[v] == -1)
			distDir[v]=inf;
		else
			distDir[v]=0;
		return distDir[v];
	}
	if (a[v] != -1)
	{
		distDir[v]=0;
		return 0;
	}
	distDir[v] = 1 + findDistanceDir(v-1);
	return distDir[v];
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int n;
 	cin >> n;

 	for (int i = 0; i < n; ++i)
 	{
 		cin >> a[i];
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		findDistanceEsq(i,n);
 	}
 	for (int i = n-1; i >= 0; --i)
 	{
 		findDistanceDir(i);
 	}

  	for (int i = 0; i < n; ++i)
  	{
  		cout << ( min(distDir[i], distEsq[i]) > 9 ? 9 : min(distDir[i], distEsq[i]));
  		if (i < n-1)
  			cout << " ";
  	}
  	cout << endl;
	return 0;
}
