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
#define N 112345 


ll n,m;
ll bit[N];
void update (ll u, ll x)
{
    for (ll i = u; i <=n; i+= i & -i)
    {
        bit[i]+=x;
    }
}
ll query (ll u)
{
    ll res=0;
    for (ll i = u; i ; i-= i & -i)
    {
        res+= bit[i];
    }
    return (res);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    // memset(bit, 0, sizeof bit);
    vector<int>a;
    // reads array of n elements
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        a.pb(x);
        update(i+1,x);
    }
    for (ll j = 0; j < m; ++j)
    {
        ll op;
        cin >> op;
        // op 1: update position i € [0..n) with v
        if (op == 1)
        {
            ll i,v;
            cin >> i >> v;
            v = -(a[i] - v);
            a[i] = a[i] + v;
            update(i+1,v);
        }
        // op 2: query sum of [l.. r), and l,r € [0..n)
        // query r, subtracts l from it
        else
        {
            ll l,r;
            cin >> l >> r;
            ll res;
            if (l > 0)
                res = query(r)-query(l);
            else
                res = query(r);
            printf("%lld\n", res);
        }
    }
  
    return 0;
}