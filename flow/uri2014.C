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

ll sangue[112][112];
ll antigenos[112];
ll prole[112];
ll n,q;
ll sz;
ll residuo[212][212];
ll visitado[212];
ll parent[212];
ll bfs(ll src, ll dst)
{
	memset(visitado, 0, sizeof(visitado));
	memset(parent, 0, sizeof(parent));
	queue <ll> fila;
	fila.push(src);
	visitado[src] = 1;
	parent[src] = -1;
	while (!fila.empty())
	{
		ll v = fila.front();
		// printf("%lld\n",v );
		fila.pop();
		for (ll i = 0; i < sz; ++i)
		{
			if (residuo[v][i])
			{
				if (!visitado[i])
				{
					parent[i] = v;
					visitado[i] = 1;
					fila.push(i);
				}
				if (i == dst)
				{
					// printf("sai dest\n");
					return 1;
				}
			}
		}
	}
	if (visitado[dst])
		return 1;
	// printf("sai\n");
	return 0;

}
ll fordFulkerson(ll source, ll sink)
{

	ll maxFlow = 0;
	while (bfs(source, sink))
	{
		ll v = sink;
		ll flow = iinf;
		while (v!= source)
		{
			ll u = parent[v];
			if (residuo[u][v] < flow)
				flow = residuo[u][v];
			v = u;
		}
		v = sink;
		while (v != source)
		{
			ll u = parent[v];
			residuo[u][v]-=flow;
			residuo[v][u]+=flow;
			v = u;
		}
		maxFlow+=flow;
	}
	return maxFlow;
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	scanf ("%lld %lld", &n,&q);
	// memset(antigenos, 0, sizeof(antigenos));
	for (ll i = 0; i < n; ++i)
 	{
 		ll b;
 		scanf ("%lld", &b);
 		antigenos[i]=b;
 		memset(sangue[i],0,sizeof(sangue[i]));
 		for (ll j = 0; j < b; ++j)
 		{
 			ll x;
 			scanf ("%lld", &x);
 			sangue[i][x]=1;
 		}
 		if (b < n)
 			sangue[i][0]=1;
 	}
 	for (ll i = 0; i < q; ++i)
 	{
 		ll b;
 		scanf ("%lld", &b);
 		memset(prole, 0, sizeof(prole));
 		for (ll j = 0; j < n+n+2; ++j)
 		{ 			
 			memset(residuo[j], 0, sizeof(residuo[j]));
 		}
 		for (ll j = 0; j < b; ++j)
 		{
 			scanf ("%lld", &prole[j]);
 			for (ll k = 0; k < n; ++k)
 			{
 				if (sangue[k][prole[j]])
 					residuo[k][n+j] = 1;
 			}
 			
 		}
 		if (b < n) // os outros antigens são 0 ou igual aos q ja apareceram
 			for (ll j = b; j < n; ++j)
 			{
	 			for (ll k = 0; k < n; ++k)
	 			{
	 				for (ll l = 0; l < b; ++l)
	 					if (sangue[k][prole[l]])
	 						residuo[k][n+j] = 1;
	 				if (sangue[k][0])
	 					residuo[k][n+j] = 1;
	 			}
 				
 			}
 		// source:
 		ll sink = n+n+1;
 		ll source = n+n;
 		for (ll j = 0; j < n; ++j)
 		{
 			residuo[source][j] = 1;
 		}
 		// sink:
 		for (ll j = 0; j < n; ++j)
 		{
 			residuo[n+j][sink] = 1;
 		}
 		sz = n+n+2;
 		int ans = fordFulkerson (source, sink);
 		
 		if (ans == n)
 			printf("Y\n");
 		else
 			printf("N\n");
 	} 	
  
	return 0;
}
