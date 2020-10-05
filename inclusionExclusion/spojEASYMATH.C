#include <bits/stdc++.h>
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
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
using namespace std;

map<pii, int>m;
ll gcd(ll a, ll b)
{
   ll gcd = a;
    ll tmp = b;
    while (gcd != tmp)
    {
        if (gcd > tmp)
            gcd -= tmp;
        else
            tmp-=gcd;
    }
    return gcd; 
}
ll lcm(ll a, ll b)
{
    ll men = min(a,b);
    ll mai = max(a,b);
    if (m.count(mp(men,mai)))
        return m[mp(a,b)];
    
    m[mp(a,b)] = (a*b) / gcd(a,b);
    return m[mp(a,b)];
}

// ll countDivisibles(ll A, ll B, ll M) 
// { 
//     // Add 1 explicitly as A is divisible by M 
//     if (A % M == 0) 
//         return (B / M) - (A / M) + 1; 
  
//     // A is not divisible by M 
//     return (B / M) - (A / M); 
// } 
ll countNoDivisibles(ll n, ll m, ll a, ll d)
{
    ll count=0;
    for (ll i = n; i <=m; ++i)
    {
        ll t=0;
        for (ll j = 0; j < 5; ++j)
        {
            if (i % (a+(j*d))==0)
                t++;            
        }
        // printf("%d, ",i );
        // printf("%d\n",t <5);
        // printf("%d\n",t );
        if (!t)
        {
            // printf("dsdsa\n");
            count++;
        }
    }
    return count;
}
ll countDivisibles2(ll x, ll y, ll z)
{
    ll xmod = x%z;
    if (xmod)
        x += (z - xmod);
    y -= y % z;
    if(x > y)
      return 0;
    else
      return (y - x) / z + 1;
}

ll count(ll a[], ll m, ll n) 
{ 
    ll odd = 0, even = 0; 
    ll counter, i, j, p = 1; 
    ll pow_set_size = (1 << n); 

    // Run from counter 000..0 to 111..1 
    for (counter = 1; counter < pow_set_size; 
                                counter++) 
    { 
        p = 1; 
        for (j = 0; j < n; j++) 
        { 

            if (counter & (1 << j)) 
            { 
                p = lcm(p, a[j]);
            } 
        } 
        if (__builtin_popcount(counter) & 1) 
            odd += m/p; 
        else
            even += m/p; 
    } 

    return odd - even; 
} 
ll include_exclude(ll n, ll a[5]) { 
  ll ret = 0; 
 
  // Loop over the bitmasks from 0 to 2^5-1 
  for (int bitmask = 0; bitmask < (1 << 5); ++bitmask) { 
    ll lcm = 1;  // LCM of the numbers in the set 
    int sign = 1;       // The sign in the sum depending on element count 
    for (int i = 0; i < 5; ++i) { 
      // Is the ith bit set? 
      if (bitmask & (1 << i)) { 
        sign = -sign; 
        ll g = gcd(lcm, a[i]);  // Because lcm(a,b) = ab/gcd(a,b) 
 
        // Will multiplying lcm by a[i] / g take us above n? 
        // Then stop and avoid overflow 
        if (n / lcm < a[i] / g) { 
          lcm = n + 1;  // This will not add anything to the sum 
          break; 
        } 
 
        // Otherwise update the lcm 
        lcm *= a[i] / g; 
      } 
    } 
 
    ret += sign * (n / lcm); 
  } 
  return ret; 
} 

long long include_exclude_v2(int n, int a[5]) { 
  long long ret = n, lcm[1 << 5] = {1}, sign[1 << 5] = {1}; 
 
  for (int i = 0; i < 5; ++i) { 
    // Process the ith element: Add a[i] to every set processed till now 
    for (int j = 0, k = 1 << i; j < (1 << i); ++j, ++k) { 
      sign[k] = -sign[j]; 
      long long g = gcd(lcm[j], a[i]); 
      if (n / lcm[j] < a[i] / g) { 
        lcm[k] = n + 1; 
      } else { 
        lcm[k] = lcm[j] * (a[i] / g); 
      } 
      ret += sign[k] * (n / lcm[k]); 
    } 
  } 
 
  return ret; 
} 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m,a,d;
        cin >> n >> m >> a >> d;
        ll vec[5];
        ll sz = 5;
        for (ll i = 0; i < 5; ++i)
        {
            vec[i] = a+i*d;            
        }
        ll ans = include_exclude(m,vec);
        ans = ans - include_exclude(n-1,vec);
        // ll ans =  count(vec, m, sz);
        // ans = ans - ( count(vec, n-1, sz));
        printf("%lld\n", ans );
        // printf("%lld\n", countNoDivisibles(n,m,a,d));

        
    }
  
    return 0;
}
