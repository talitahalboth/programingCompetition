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
	double operator~ () const
	{
		// dot operator
		// {*this * *this}
		// or hypotenuse
		return { hypot (x,y)};
	}

	// distance between r and the segment pq
	double disPointLine(TVector p, TVector q)
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

	ll sqrdDist(TVector p)
	{

    	return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y); 
	}
	ll orientation(/*Point p,*/ TVector b, TVector c) 
	{ 
		TVector a = *this;


	    int val =  (c-a)^(b-a);
	    return val;
	  
	    // if (val == 0) return 0;  // colinear 
	    // return (val > 0)? 1: 2; // clock or counterclock wise 
	}
};

struct comparator
{
	TVector o;
	bool operator()(TVector a, TVector b) const
	{
		int val = (a-o)^(b-o);
		if (val == 0)
			return(a.sqrdDist(o) < b.sqrdDist(o) );
		return ( val  >= 0 );
	}
};

bool xyd(double x,double y)	{	return x < y + EPS;} 	// x <= y 

vector <TVector> points;
TVector convexHull[112345];
int grahamScan()
{
	// encontra menor ponto
	int minIn = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		if (points[i].x < points[minIn].x )
			minIn = i;
		else if (points[i].x == points[minIn].x && points[i].y < points[minIn].y)
			minIn = i;
	}
	comparator o; // origin
	o.o=points[minIn];
	// polar angle sort
	sort(all(points), comparator(o));

	convexHull[0] = points[0]; convexHull[1] = points[1];
    int top = 1;
	for(int i=2; i<points.size(); i++)
	{
		while(xyd(convexHull[top].orientation(convexHull[top-1],points[i]), 0.0) && top >= 1)
			top--;
		convexHull[++top] = points[i];
	}
	return top+1;
}

int main(){
 		points.clear();
 		ll n;
 	 	cin >> n;
	 	for (ll i = 0; i < n; ++i)
	 	{
	 		ll x,y;
	 		cin >> x >> y;
	 		TVector tmp;
	 		tmp.x=x;
	 		tmp.y=y;
	 		points.pb(tmp);
	 	}
 		int n2=grahamScan();
 		if (n2 == 2)
 		{
 			if (convexHull[0].x == convexHull[1].x && convexHull[0].y == convexHull[1].y)
 			{
 				cout << 1 << endl;
 				cout << convexHull[0].x << " " <<convexHull[0].y<<endl;
 				// printf("%d\n",1 );
 				// printf("%d %d\n",convexHull[0].x,convexHull[0].y );
 			}
 			else
 			{

	 		cout << n2 << endl;
	 	 	for (ll i = 0; i < n2; ++i)
	 	 	{
	 	 		cout << convexHull[i].x << " "<< convexHull[i].y << endl;
	 	 		// printf("%d %d\n",convexHull[i].x ,convexHull[i].y);
	 	 	}
 			}

 		}
 		else
 		{
	 		cout << n2 << endl;
	 	 	for (ll i = 0; i < n2; ++i)
	 	 	{
	 	 		cout << convexHull[i].x << " "<< convexHull[i].y << endl;
	 	 		// printf("%d %d\n",convexHull[i].x ,convexHull[i].y);
	 	 	}
	 	 }
  
	return 0;
}
