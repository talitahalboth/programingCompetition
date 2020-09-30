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
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

vector<int> vetor;
int bbFirst(int elem)
{
    int sup = vetor.size()-1;
    int inf = -1;
    // int elem = v+1;
    int mid;
    while (sup > inf)
    {
        // printf("%d %d\n", sup, inf);
        mid = inf + (sup-inf+1)/2;
        if (vetor[mid] < elem)
            inf = mid;
        else if (vetor[mid] >= elem)
            sup = mid-1; 
    }
    return sup;
}

int bbLast(int elem)
{
    int sup = vetor.size();
    int inf = 0;
    // int elem = v+1;
    int mid;
    while (sup > inf)
    {
        // printf("%d %d\n", sup, inf);
        mid = inf + (sup-inf)/2;
        if (vetor[mid] <= elem)
            inf = mid+1;
        else if (vetor[mid] > elem)
            sup = mid; 
    }
    return sup;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        vetor.pb(a);
    }
    int e;
    while (cin >> e)
    {
        printf("primeiro menor que %d :%d\n",e, bbFirst(e) );
        printf("primeiro maior :%d\n", bbLast(e));
    }
    return 0;
}