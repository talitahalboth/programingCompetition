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
#define NEXT 21252
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;
int a[3];
int b[3]; // n
int m[3];
int mi[3];
int inv(int a, int m) 
{ 
    int m0 = m, t, q; 
    int x0 = 0, x1 = 1; 
  
    if (m == 1) 
       return 0; 
    // Apply extended Euclid Algorithm 
    while (a > 1) 
    { 
        // q is quotient 
        q = a / m; 
        t = m;   
        // m is remainder now, process same as 
        // euclid's algo 
        m = a % m, a = t;   
        t = x0;   
        x0 = x1 - q * x0;   
        x1 = t; 
    } 
  
    // Make x1 positive 
    if (x1 < 0) 
       x1 += m0; 
  
    return x1; 
} 
  
// k is size of num[] and rem[].  Returns the smallest 
// number x such that: 
//  x % num[0] = rem[0], 
//  x % num[1] = rem[1], 
//  .................. 
//  x % num[k-2] = rem[k-1] 
// Assumption: Numbers in num[] are pairwise coprime 
// (gcd for every pair is 1) 
int findMinX(int num[], int rem[], int k) 
{ 
    // Compute product of all numbers 
    int prod = 1; 
    for (int i = 0; i < k; i++) 
        prod *= num[i]; 
  
    // Initialize result 
    int result = 0; 
  
    // Apply above formula 
    for (int i = 0; i < k; i++) 
    { 
        int pp = prod / num[i]; 
        result += rem[i] * inv(pp, num[i]) * pp; 
    } 
  
    return result % prod; 
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p,e,i,d;
    cin >> p >> e >> i >>d;
    int caso=1;
    b[0] = 23;
    b[1] = 28;
    b[2] = 33;
    while (p!=-1)
    {
        a[0] = p;
        a[1] = e;
        a[2] = i;
        // ll x = solve();
        // int num[] = {3, 4, 5}; 
        // int rem[] = {2, 3, 1}; 
        int k = sizeof(a)/sizeof(a[0]); 
        ll x = findMinX(b,a, k); 
        ll days = x - d ;
        days += 21251;
        days %= 21252;
        printf("Case %lld: the next triple peak occurs in %lld days.\n", caso++, days+1);

        // x = p mod 23
        // x = e mod 28
        // x = i mod 33
        // p,e,i:number of days from the beginning of the current year 
        // at which the physical, emotional, and intellectual cycles peak

        // d is the given date
        cin >> p >> e >> i >>d;
    }
  
    return 0;
}
