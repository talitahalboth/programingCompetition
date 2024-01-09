#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
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
    bool isAlpha(char c)
    {
        
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.size() -1;
        while (i < j)
        {
            while (i < j && !isAlpha(s[i]) ) i+=1;
            while (j > i && !isAlpha(s[j]) ) j-=1;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
        
    }
int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    cout << (isPalindrome(
        "   "
        ) == true ? "true" : "false");
    return 0;
}