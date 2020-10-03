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
typedef int item;
// struct item
// {
//     ll i;
    
// };


struct segtree 
{
    ll size;
    vector<item> value;

    item NEUTRAL_ELEM = 0;
    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        return (a+b);
    }

    item single(ll v)
    {
        return v;
    }
    pair <int, int> child(int x)
    {
        return {2*x+1, 2*x+2};
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
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

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i,ll v, ll x, ll lx, ll rx)
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
    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r) return value[x];

        int m = (lx+rx)/2;
        ll s1 = sum(l,r,x*2+1, lx, m);
        ll s2 = sum(l,r,x*2+2, m, rx);
        return merge(s1,s2);
    }
    ll sum(int l, int r)
    {
        if (l==r)
            return 0;
        return sum(l,r,0,0,size);
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q;
    cin >> n >> q;
    segtree st;
    st.init(41);
    vector<int> original;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        original.pb(x);
    }
    int freq[41];
    for (int i = 0; i < q; ++i)
    {
        memset(freq, 0, sizeof freq);
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            ll ans=0;
            for (int i = l; i < r; ++i)
            {
                ans+=st.sum(original[i],41);
                freq[original[i]]++;
                st.set(original[i]-1,freq[original[i]]);
            }
            for (int i = 0; i < 41; ++i)
            {
                st.set(i,0);
            }
            printf("%lld\n",ans);

        }
        else
        {
            int in,v;
            cin >> in >> v;
            original[in-1]=v;
        }
    }
  
    return 0;
}
