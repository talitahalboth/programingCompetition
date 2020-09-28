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
#define pll pair<ll, ll>
using namespace std;

struct item
{
    ll seg, pref, suf, sum;    
};

struct segtree 
{
    ll size;
    vector<item> value;

    item NEUTRAL_ELEM = {0,0,0,0};
    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        ll seg = max(a.seg, max(b.seg, a.suf+b.pref));
        ll pref = max(a.pref, a.sum+b.pref);
        ll suf = max(b.suf, b.sum + a.suf);
        ll sum = a.sum+b.sum;
        return{ seg, pref, suf, sum};
    }

    item single(ll v)
    {
        ll maior = v>0?v:0;
        return {maior, maior, maior, v};
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
            {
                value[x] = single(a[lx]);
            }
            return;
        }
        ll m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        value[x] = merge(value[2*x+1],  value[2*x+2]);

    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            value[x]=single(v);
            return;
        }
        ll m = (lx+rx)/2;
        if (i < m)
        {
            set(i,v,2*x+1, lx, m);
        }
        else
        {
            set(i,v,2*x+2, m, rx);
        }
        value[x] = merge(value[2*x+1],  value[2*x+2]);
    }
    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    item find(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEM;
        if (lx >= l && rx <= r) return value[x];

        ll m = (lx+rx)/2;
        item s1 = find(l,r,x*2+1, lx, m);
        item s2 = find(l,r,x*2+2, m, rx);
        return merge(s1,s2);
    }

    item find(ll l, ll r)
    {
        return find(l,r,0,0,size);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];        
    }
    st.build(a);
    printf("%lld\n",st.value[0].seg);
    while(m--)
    {
        ll i,v;
        cin >> i >> v;
        st.set(i,v);
        printf("%lld\n",st.value[0].seg);
        
    }
  
    return 0;
}
