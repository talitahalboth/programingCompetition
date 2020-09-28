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
// a · x^2 + b mod N
ll n;
ll a;
ll b;
ll f( ll x)
{
    ll tmp = (a*x)%n;
    tmp = (tmp * x)%n;
    return (tmp+b) % n;
}

pll floydCycleFinding()
{
    ll tortoise = f(0);
    ll hare = f(f(0));
    while (tortoise!= hare)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    ll mu=0;
    hare = 0;
    while(tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    ll lambda=1;
    hare = f(tortoise);
    while (tortoise != hare)
    {
        hare = f(hare);
        lambda++;
    }
    // mu -> start of the cycle
    // lambda -> cycle length
    return mp(mu, lambda);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    // printf("start\n");
    while (cin >> n >> a >> b)
    {
        pll p = floydCycleFinding();
        printf("%lld\n", n - p.se);
    }

  
    return 0;
}
