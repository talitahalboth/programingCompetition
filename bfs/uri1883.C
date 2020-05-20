#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (ll (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (ll (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (ll (X) = (Y)-1;(X) >=0;--(X))
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

ll dungeon[1123][1123];
ll visitados[1123][1123];
ll bfs2( pii start, pii end, ll n, ll m)
{
	ll dx[] = {1, -1, 0, 0};
	ll dy[] = {0, 0, 1, -1};

	for (int i = 0; i < 1123; ++i)
	{
		memset(visitados[i],0,sizeof(visitados[i]));
	}
	
	queue <pii> fila;
	visitados[start.fi][start.se] = 1;
	fila.push(start);
	while (!fila.empty())
	{
		pii v = fila.front();
		fila.pop();
		for (ll i = 0; i < 4; ++i)
		{
			ll vx = v.fi + dx[i];
			ll vy = v.se + dy[i];
			if(vx < 0 or vx >= n) continue;
			if(vy < 0 or vy >= m) continue;
			// if (dungeon[vx][vy] == 2)
			if (dungeon[vx][vy])
			{
				if (!visitados[vx][vy])
				{
					visitados[vx][vy] = visitados[v.fi][v.se]+1;
					fila.push(mp(vx,vy));
				}
				if (dungeon[vx][vy] == 2)
				{
					return visitados[vx][vy]-1;
				}
			}

			
		}

	}
	return -1;

}
int bfs( pii start, pii end, int n, int m)
{
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	

	for (int i = 0; i < 1123; ++i)
	{
		memset(visitados[i],0,sizeof(visitados[i]));
	}
	queue <pii> fila;
	visitados[start.fi][start.se] = 1;
	fila.push(start);
	while (!fila.empty())
	{
		pii v = fila.front();
		fila.pop();
		for (int i = 0; i < 4; ++i)
		{
			int vx = v.fi + dx[i];
			int vy = v.se + dy[i];
			if(vx < 0 or vx >= n) continue;
			if(vy < 0 or vy >= m) continue;
			if (dungeon[vx][vy] == 1)
			{
				if (!visitados[vx][vy])
				{
					visitados[vx][vy] = visitados[v.fi][v.se]+1;
					fila.push(mp(vx,vy));
				}
				if (vx == end.fi && vy == end.se)
					return visitados[vx][vy]-1;
			}

			
		}

	}
	return -1;

}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	ll t;
 	cin >> t;
 	for (ll T = 0; T < t; ++T)
 	{
 		ll n,m;
 		cin >> n >> m;
 		pii start;
 		pii end;
 		vector <pii> fires;
 		fires.clear();
 		for (ll i = 0; i < n; ++i)
 		{
 			for (ll j = 0; j < m; ++j)
 			{
 				char c;
 				cin >> c;
 				if (c == '.')
 					dungeon[i][j]=1;
 				else if (c=='#')
 					dungeon[i][j] = 0;
 				else if (c=='F')
 				{
 					fires.pb(mp(i,j));
 					dungeon[i][j] = 2;
 				}
 				else if (c == 'S')
 				{
 					dungeon[i][j] = 1;
 					start = {i,j};
 				}
 				else if (c == 'E')
 				{
 					dungeon[i][j] = 1;
 					end = {i,j};
 				}

 			}
 		}
 		ll poss = 1;
 		ll time = bfs(start, end, n, m);
 		if (time < 0)
 			poss = 0;
 		ll time2 = bfs2(end, start, n, m);
 		if (time >= time2)
 			poss = 0;
		if (poss)
			printf("Y\n");
		else
			printf("N\n");


 	}
  
	return 0;
}
