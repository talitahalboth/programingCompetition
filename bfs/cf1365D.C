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

ll mat[100][100];
ll visited[100][100];
int leadsToEnd[100][100];
ll n;
ll m;
ll bfs(pii start)
{
	for (ll i = 0; i < 51; ++i)
	{
		memset(visited[i], 0, sizeof(visited[i]));
	}
	queue<pii> fila;
	visited[start.fi][start.se] = 1;
	fila.push(start);
	while (!fila.empty())
	{
		pii v = fila.front();
		fila.pop();
		ll x = v.fi;
		ll y = v.se;
		if (leadsToEnd[x][y])
			return 1;
		ll dx[] = {1, -1, 0, 0};
		ll dy[] = {0, 0, 1, -1};
		for(ll i = 0; i < 4; i++)
		{
			ll vx = x + dx[i], vy = y + dy[i];
			if(vx < 0 or vx >= n) continue;
			if(vy < 0 or vy >= m) continue;

			if (mat[vx][vy] == 3 || (leadsToEnd[vx][vy]))
				return 1;
			if (!visited[vx][vy] &&  mat[vx][vy])
			{
				visited[vx][vy] = 1;
				fila.push(mp(vx,vy));

			}
		}
		
	}
	return 0;
}
int setLeadToEnd(pii start)
{
	for (ll i = 0; i < 51; ++i)
	{
		memset(visited[i], 0, sizeof(visited[i]));
	}
	queue<pii> fila;
	visited[start.fi][start.se] = 1;
	fila.push(start);
	while (!fila.empty())
	{
		pii v = fila.front();
		fila.pop();
		ll x = v.fi;
		ll y = v.se;
		ll dx[] = {1, -1, 0, 0};
		ll dy[] = {0, 0, 1, -1};
		for(ll i = 0; i < 4; i++)
		{
			ll vx = x + dx[i], vy = y + dy[i];
			if(vx < 0 or vx >= n) continue;
			if(vy < 0 or vy >= m) continue;

			
			if (!visited[vx][vy] &&  mat[vx][vy])
			{
				visited[vx][vy] = 1;
				leadsToEnd[vx][vy]=1;
				fila.push(mp(vx,vy));

			}
		}
		
	}
	return 0;
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);

  	ll t;
  	cin >> t;
  	for (ll T = 0; T < t; ++T)
  	{
  		ll good =0;
  		ll bad =0;
  		vector<pii>badCoord;
  		badCoord.clear();
  		vector<pii>goodCoord;
  		goodCoord.clear();
  		cin >> n >> m;
  		for (ll i = 0; i < n; ++i)
  		{
  			for (ll j = 0; j < m; ++j)
  			{
  				char c;
  				cin >> c;
  				if (c == '.')
  					mat[i][j]=-1;
  				else if (c=='#')
  					mat[i][j]=0;
  				else if (c=='G')
  				{
  					good++;
  					goodCoord.pb(mp(i,j));
  					mat[i][j]=1;
  				}
  				else if (c=='B')
  				{
  					bad++;
  					badCoord.pb(mp(i,j));
  					mat[i][j]=2;
  				}
  			}
  		}
  		// saida
  		mat[n-1][m-1] = 3;
  		ll poss = 1;
  		for (ll i = 0; i < badCoord.size(); ++i)
  		{
  			ll x = badCoord[i].fi;
  			ll y = badCoord[i].se;
  			ll dx[] = {1, -1, 0, 0};
			ll dy[] = {0, 0, 1, -1};
			for(ll i = 0; i < 4; i++)
			{
				ll vx = x + dx[i], vy = y + dy[i];
				if(vx < 0 or vx >= n) continue;
				if(vy < 0 or vy >= m) continue;
				if (mat[vx][vy] == 1 || (mat[vx][vy] == 3 && good))
					poss = 0;
				else if (mat[vx][vy] == -1)
					mat[vx][vy] = 0;

			}

  		}

  		ll goodLeave = 0;
  		for (int i = 0; i < 50; ++i)
  		{
  			memset(leadsToEnd,0,sizeof(leadsToEnd));
  		}
  		setLeadToEnd(mp(n-1,m-1));
  		for (ll i = 0; i < goodCoord.size(); ++i)
  		{
  			goodLeave+=leadsToEnd[goodCoord[i].fi][goodCoord[i].se];
  			// goodLeave+=bfs(goodCoord[i]);
  			
  		}
  		if (goodLeave < good)
  			poss = 0;
  		// ll badLeave = 0;
  		// for (ll i = 0; i < badCoord.size(); ++i)
  		// {
  		// 	badLeave+=bfs(badCoord[i]);
  			
  		// }
  		// for (ll i = 0; i < n; ++i)
  		// {
  		// 	for (ll j = 0; j < m; ++j)
  		// 	{
  		// 		printf("%d ",mat[i][j] );
  		// 	}
  		// 	printf("\n");
  		// }
  		// if (badLeave > 0)
  		// 	poss = 0;
  		if (!good)
  			poss = 1;
  		if (poss)
  			printf("Yes\n");
  		else
  			printf("No\n");
  	}
	return 0;
}