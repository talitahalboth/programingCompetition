#include <iostream>
#include <cstdint>
#include <stack>
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
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> s;
        string str;
        cin >> str;
        for (int i = 0; i < n; i++)
        {
            int curr = str[i]== '-' ? 0 : 1;
            if (s.empty())
                s.push(curr);
            else 
            {
                if (s.top() != curr)
                    s.pop();
                else
                    s.push(curr);
            }
        }
        cout << s.size() << endl;

                
    }
  
    return 0;
}