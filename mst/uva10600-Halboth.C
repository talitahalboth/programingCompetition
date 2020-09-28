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


int w[1123][1123],p[1123],n,m,cont = 0;
int ans=0;
vector<int> usados;
void init()
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			w[i][j]=iinf;
		}
		p[i]=-1;
	}
	usados.clear();
}
vector<pair <int, pii>> edges;
void kruskal()
{
	int min,ne=0,i,j,u,v,a,b;
	int next=0;
	while(ne<n-1 && min!=iinf)
	{
		min=iinf;
		u=a= edges[next].se.fi;
		v=b= edges[next].se.se;
		min = edges[next].fi;

		while(p[u] != -1)
			u=p[u];
		while(p[v] != -1)
			v=p[v];
		//confere se não forma um ciclo
		if(u!=v)
		{
			usados.pb(next);
			ne++;
			ans+=min;
			p[v]=u;
		}
		next++;
		// muda o peso da aresta para ‘infinito’
		w[a][b]=w[b][a]=iinf;
	}
}

int kruskal2()
{
	int res=iinf;
	for (int i = 0; i < usados.size(); ++i)
	{
		// printf("usado:%d\n",usados[i] );
		int min=0,ne=0,u,v,a,b;
		int next=0;
		int tmpRes=0;
		int times=0;
		for (int i = 0; i <= n; ++i)
			p[i]=-1;
		while(ne<n-1 && min!=iinf && next < edges.size())
		{
			// printf("%d\n",ne );
			min =0;
			if (next != usados[i])
			{
				min=iinf;
			
				// 	return ans;
				u=a= edges[next].se.fi;
				v=b= edges[next].se.se;
				min = edges[next].fi;

				while(p[u] != -1)
					u=p[u];
				while(p[v] != -1)
					v=p[v];
				//confere se não forma um ciclo
				if(u!=v)
				{
					ne++;
					tmpRes+=min;
					p[v]=u;
				}
			}
			next++;
		}
		if(tmpRes < res && ne == n-1)
			res = tmpRes;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		edges.clear();
		scanf ("%d %d", &n, &m);
		int x=0,y=0,z=0;
		//zera a matrizz
		init();
		ans=0;

		//zera o p
		// memset (p, 0, sizeof(p[0])*1000);
		for (int i = 0; i < m; ++i)
		{
			scanf ("%d %d %d", &x, &y, &z);
			x--;
			y--;
			// z vai pra pos. [x][y]
			// edges.pb(mp(z, mp(x,y)));
			edges.pb(mp(z, mp(y,x)));
		}
		sort(all(edges));
		// printf("Teste %d\n",++cont );
		kruskal();
		printf("%d ",ans );
		// if (edges.size() > n-1)
			printf("%d\n",kruskal2() );
		// else
		// 	printf("%d\n",ans );
		// printf("\n");
		// scanf ("%d %d", &n, &m);
	}
	return 0;
}