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
struct point {
	int x,y;
	point () {}
	point( int _x, int _y): x(_x), y(_y){}
};

struct vec {
	int x,y;
	vec () {}
	vec( int _x, int _y): x(_x), y(_y){}
	vec(point a, point b): x(b.x - a.x), y(b.y - a.y){}
};
// produto escalar
int dot(vec u, vec v){ return u.x*v.x + u.y * v.y; }
// produto vetorial
int cross(vec u, vec v){ return u.x*v.y - u.y*v.x; }
// counter clockwise test
int ccw(point a, point b, point c)
{
	return cross(vec(a,b), vec(a,c));
}
double angle(point a, point b, point c)
{
	vec u(b, a), v(b, c);
	return acos(dot(u,v) * sqrt(dot(u,u) * dot (v,v)));
}

int estaNaEsquerda(point a, point b, point c)
{
	// (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)
	int res = (b.x - a.x)*(c.y-a.y) - (c.x - a.x)*(b.y-a.y);
	// c está a esquerda de ab
	if (res > EPS)
		return 1;
	// c está a direita ab
	if (res < -EPS)
		return -1;
	// c e ab são colineares
	return 0;

}
vector <int> arr;
bool compareIndices(int i, int j)
{
	return (arr[i] < arr[j]);
}
void merge(int low, int high, int mid)
{
    int i, j, k;
    int c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) 
    {
        if (compareIndices(i,j)) 
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) 
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) 
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  
    {
        arr[i] = c[i];
    }
}
void merge_sort(int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        //merge or conquer sorted arrays
        merge(low,high,mid);
    }
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);

  
	return 0;
}
