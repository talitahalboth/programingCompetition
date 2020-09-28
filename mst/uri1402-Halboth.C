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

bool essentiallyEqual(float a, float b)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPS);
}

struct TVector {
	ll x,y;
	// sum vectors
	TVector operator+ (TVector q) const
	{
		return {x+q.x, y+q.y};
	}
	// subtract vectors
	TVector operator- (TVector q) const
	{
		return {x-q.x, y-q.y};
	}
	// multiplication by scalar
	TVector operator* (int t) const
	{
		return {x*t, y*t};
	}
	
	// dot product
	// if 0: 90 or 270º
	// > 0: a<90
	// < 0: a>90
	ll operator*(TVector q) const
	{
		return {x*q.x + y*q.y};
	}
	// if 0:  0 or 180º
	// if > 0: counter clockwise
	// else clockwise {

	// cross product
	ll operator^(TVector q) const
	{
		return {x*q.y - q.x*y};
	}

	// lenght of vector
	long double operator~ () const
	{
		// dot operator
		// {*this * *this}
		// or hypotenuse
		return { hypot (x,y)};
	}

	// distance between r and the segment pq
	long double disPointLine(TVector p, TVector q)
	{
		TVector r = *this;
		if ( ((r-p)*(q-p)>=0) && ((r-q)*(p-q) >=0))
		{
			return abs( (q-p)^(r-p)) / ~(p-q);
		}
		else
		{
			return min(~(r-p), ~(r-q) );
		}
	}
	// point on segment pq
	bool onLine( TVector p, TVector q)
	{
		TVector r = *this;

		long double dis = r.disPointLine(p,q);
		return essentiallyEqual(dis,0);
		// // printf("dis: %lf\n", dis);
		if (x <= max(p.x, q.x) && x >= min (p.x, q.x)  &&
			(y <= max(p.y, q.y)) && y >= min (p.y, q.y) )
			return true;
		return false;
	}

	long double sqrdDist(TVector p)
	{

    	return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y); 
	}
	int orientation(/*Point p,*/ TVector b, TVector c) 
	{ 
		TVector a = *this;


	    int val =  (c-a)^(b-a);
	    return val;
	}
	int orientationV2(/*Point p,*/ TVector b, TVector c) 
	{ 
		TVector a = *this;


	    int val =  (c-a)^(b-a);	  
	    if (val == 0) return 0;  // colinear 
	    return (val > 0)? 1: 2; // clock or counterclock wise 
	}
	void imprimePonto()
	{
		printf("%lld %lld",x,y );
	}
};

struct TSegment
{
	TVector a,b;

	int intersect(TSegment cd)
	{
		int dir1,dir2,dir3,dir4;
		dir1 = a.orientationV2(b,cd.a);
		dir2 = a.orientationV2(b,cd.b);
		dir3 = cd.a.orientationV2(cd.b,a);
		dir4 = cd.a.orientationV2(cd.b,b);
   
	   if(dir1 != dir2 && dir3 != dir4)
	   {
			return true; //they are intersecting
	   }

	   if(dir1==0 &&  cd.a.onLine(a,b)) //when p2 of line2 are on the line1
	   {
			return true;
	   }

		if(dir2==0 &&  cd.b.onLine(a,b)) //when p1 of line2 are on the line1
		{
			return true;
		}

		if(dir3==0 &&  a.onLine(cd.a,cd.b)) //when p2 of line1 are on the line2
		{
			return true;
		}

		if(dir4==0 &&  b.onLine(cd.a,cd.b)) //when p1 of line1 are on the line2
		{
			return true;
		}
		 
		return false;
	}
	long double disSegSeg(TSegment cd)
	{
		if (a.x ==b.x && a.y==b.y)
			return a.disPointLine(cd.a, cd.b);
		if (cd.a.x == cd.b.x && cd.a.y==cd.b.y)
			return cd.a.disPointLine(a, b);
		TSegment ab = *this;
		if (ab.intersect(cd))
			return 0;
		long double a_cd = a.disPointLine(cd.a, cd.b);
		long double b_cd = b.disPointLine(cd.a, cd.b);
		long double c_ab = cd.a.disPointLine(a, b);
		long double d_ab = cd.b.disPointLine(a, b);
		a_cd = min(a_cd, b_cd);
		c_ab = min(c_ab, d_ab);
		return min(a_cd, c_ab);
	}
	void imprimeSeg()
	{
		a.imprimePonto();
		printf(" ");
		b.imprimePonto();
		printf("\n");
	}
};



int n;

vector <TSegment> positions; 

long double dist[1123][1123];


int p[1123];
int ans=0;
vector<int> usados;
vector<pair <long double, pii>> edges;
vector <long double> tree[1123];
void init()
{
	positions.clear();
	edges.clear();
	for (int i = 0; i <= n; ++i)
	{
		p[i]=-1;
		tree[i].clear();
		for (int j = 0; j <=n; ++j)
		{
			dist[i][j]=0;
		}
	}
	usados.clear();
}
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
		if(u!=v)
		{
			tree[a].pb(b);
			tree[b].pb(a);
			usados.pb(next);
			ne++;
			ans+=min;
			p[v]=u;
		}
		next++;
	}
}
int visited[1123];
int parent[1123];
long double bfs()
{
	int start = 0;
	int end = 1;
	memset(visited, 0, sizeof visited);
	memset(parent, 0, sizeof parent);
	queue<int> fila;
	visited[start] = 1;
	fila.push(start);
	long double maxPath =0;
	parent[0]=-1;
	while (!fila.empty())
	{
		int v = fila.front();
		fila.pop();
		for (int i = 0; i < tree[v].size(); ++i)
		{
			int u = tree[v][i];
			if (!visited[u])
			{
				visited[u]=1;
				parent[u]=v;
				fila.push(u);
				if (dist[v][u] > maxPath)
					maxPath = dist[v][u];
			}
			if (u == end)
				break;
		}
		
	}
	maxPath =0;
	int v = 1;

	while (parent[v] != -1)
	{
		int u = parent[v];
		if (dist[v][u] > maxPath)
			maxPath = dist[v][u];
		v = u;

	}
	return maxPath;
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
  	while(cin >> n, n)
  	{

  		for (int i = 0; i < n; ++i)
  		{
			TSegment seg;
	  		int x,y,l;
	  		cin >> x >> y >> l;	

	  			seg.a.x=x;
	  			seg.a.y=y;
	  			if (l>0)
	  			{
		  			seg.b.x=x+abs(l);
		  			seg.b.y=y;
	  			}
	  			else
	  			{
		  			seg.b.x=x;
		  			seg.b.y=y+abs(l);
	  			}
	  			positions.pb(seg);
  		}

  		init();
  		for (int i = 0; i < n; ++i)
  		{
  			for (int j = i+1; j < n; ++j)
  			{
  				dist[i][j] = positions[i].disSegSeg(positions[j]);
  				dist[j][i] = positions[i].disSegSeg(positions[j]);
  				edges.pb(mp(dist[i][j],mp(i,j)));
  			}
  		}
  		sort(all(edges));
  		kruskal();
  		printf("%.2LF\n",bfs());
  	}
	return 0;
}
