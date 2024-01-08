#include <iostream>
#include <cstdint>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
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
#define dijkstra  0x3f3f3f3f
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
#define int long long
using namespace std;

// vector <int> a;
vector <int> b;
vector <int> c;

// void insertElementInArray(int elem, int x, int y, vector<int> a, vector<int>b)
// {
//     if (elem <= x || y < elem)
//     {
//         a.push_back(elem);
//
//         return;
//     }
//     b.push_back(elem);
// }

int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {    
        b.clear(); 
        c.clear();
        int n;
        cin >> n;
        int elem;
        while (n-- )
        {
            cin >> elem;
            if (b.size() == 0)
            {
                b.push_back(elem);
            } 
            else 
            {
                int x = b.back();
                int y = c.size() == 0 ? iinf : c.back();
                if (x < y)
                {
                     if (elem <= x || y < elem)
                    {
                        b.push_back(elem);
                    } else c.push_back(elem);
                }
                else
                {
                     if (elem <= y || x < elem)
                    {
                        c.push_back(elem);
                    } else b.push_back(elem);
                }
            }
        }
        int res = 0;
        for(int i = 1; i < b.size(); i++){
            if (b[i-1] < b[i]) res+=1;
        }

        for(int i = 1; i < c.size(); i++)
        {
            if (c[i-1] < c[i]) res+=1;
        }

        printf("%d\n", res);
        

        
    }
    return 0;
}