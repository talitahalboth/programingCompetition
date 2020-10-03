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
// typedef int item;
struct item
{
    ll a1,a2,b1,b2;    
};


struct segtree 
{
    ll size;
    vector<item> value;
    ll mod;

    item NEUTRAL_ELEM = {1LL,0LL,0LL,1LL};
    void init(ll n, ll modEl)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);
        mod = modEl;

    }
    item merge(item a, item b)
    {
        ll c11,c12,c21,c22;
        c11 = (a.a1*b.a1)%mod+(a.a2*b.b1)%mod;
        c12 = (a.a1*b.a2)%mod+(a.a2*b.b2)%mod;
        c21 = (a.b1*b.a1)%mod+(a.b2*b.b1)%mod;
        c22 = (a.b1*b.a2)%mod+(a.b2*b.b2)%mod;
        return {c11%mod,c12%mod,c21%mod,c22%mod};
    }

    item single(item v)
    {
        return v;
    }
    pair <int, int> child(int x)
    {
        return {2*x+1, 2*x+2};
    }
    void build(vector<item> &a, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
                value[x] = single(a[lx]);
            return;
        }
        ll m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        value[x] = merge(value[2*x+1],  value[2*x+2]);

    }

    void build(vector<item> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i,item v, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            value[x]=single(v);
            return;
        }
        int m = (lx+rx)/2;
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
    void set(ll i, item v)
    {
        set(i,v,0,0,size);
    }

    item mult(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEM;
        if (lx >= l && rx <= r) return value[x];

        int m = (lx+rx)/2;
        item s1 = mult(l,r,x*2+1, lx, m);
        item s2 = mult(l,r,x*2+2, m, rx);
        return merge(s1,s2);
    }
    item mult(int l, int r)
    {
        return mult(l,r,0,0,size);
    }
};

void printitem(item it)
{
    printf("%lld %lld\n%lld %lld\n\n",it.a1, it.a2,it.b1,it.b2 );
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m,r;
    cin >> r >> n >> m;
    segtree st;
    st.init(n,r);
    vector<item>a;
    for (int i = 0; i < n; ++i)
    {
        item it;
        cin >> it.a1 >> it.a2 >> it.b1 >> it.b2;
        a.pb(it);
    }
    st.build(a);
    for (int i = 0; i < m; ++i)
    {
        int l,r;
        cin >> l >> r;
        item ans = st.mult(l-1,r);
        printitem(ans);

    }

  
    return 0;
}
