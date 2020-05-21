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

char labirinto[112][112];
int visitados[112][112][(1<<7)+1];
pii ini;
pii outDoor;
int n;
int m;
int borderCheck(int i, int sz)
{
	if (i >= 0 && i < sz)
		return 1;
	return 0;
}

ll bfs(pii v)
{
	int mask = 0;
	queue <pair <int, pii>> fila;
	fila.push(mp(0, v));
	visitados[v.fi][v.se][0]=1;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	while (!fila.empty())
	{
		pair <int, pii> atual = fila.front();
		fila.pop();
		int x = atual.se.fi;
		int y = atual.se.se;
		for(int i = 0; i < 4; i++) {
			int vx = atual.se.fi + dx[i];
			int vy = atual.se.se + dy[i];
			if (borderCheck(vx,n) && borderCheck(vy,m) && labirinto[vx][vy] != '#' )
			{
				if (labirinto[vx][vy] >= 'a' && labirinto[vx][vy] <= 'g')
				{
					mask = (1 << (labirinto[vx][vy]-'a')) | atual.fi;
					if (visitados[vx][vy][mask] == 0) 
					{
						visitados[vx][vy][mask] = visitados[atual.se.fi][atual.se.se][atual.fi]+1;
						fila.push(mp(mask, mp(vx,vy)));
					}
				}
				else if(labirinto[vx][vy] >= 'A' && labirinto[vx][vy] <= 'G')
				{
					bool hasKey =((1 << (labirinto[vx][vy] - 'A')) & atual.fi)!= 0 ? true : false;
					if (hasKey && (visitados[vx][vy][atual.fi] == 0)) 
					{
						visitados[vx][vy][atual.fi] = visitados[atual.se.fi][atual.se.se][atual.fi]+1;
						fila.push(mp(atual.fi, mp(vx,vy)));
					}
				}
				else
				{
					if (labirinto[vx][vy] == '*') 
						return (visitados[atual.se.fi][atual.se.se][atual.fi]);
					if (visitados[vx][vy][atual.fi] == 0)
					{
						visitados[vx][vy][atual.fi] = visitados[x][y][atual.fi]+1;
						fila.push(mp(atual.fi, mp(vx,vy)));
					}
				}
			}
		}

	}
	return 0;
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int lines = 0;
 	// pii ini, outDoor;
 	while (scanf ("%s", labirinto[lines]) != EOF) lines++;
 	for (int i = 0; i < lines; ++i)
 	{
 		for (int j = 0; j < strlen(labirinto[i]); j++)
 		{
 			if (labirinto[i][j] == '@')
 				ini = mp(i,j);
 			else if (labirinto[i][j] == '*')
 				outDoor = mp(i,j);
 		}
 	}
 	// cout << ini.fi << " " <<ini.se << endl;
 	// cout << outDoor.fi << " " <<outDoor.se << endl;
 	n = lines;
 	m = strlen(labirinto[0]);
  	ll custo = bfs(ini);
  	// printf("dasdsa\n");
  	if (custo <= 0)
  		printf("--\n");
  	else
  		printf("%lld\n",custo );
	return 0;
}
