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

struct segtree 
{
    ll size;
    vector<ll> sums;

    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        sums.assign(2*size, 0LL);

    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
                sums[x] = a[lx];
            return;
        }
        ll m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            // cout << x << " " <<lx<<" " <<rx<<endl;
            sums[x]+=v;
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
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void set(ll i, ll v)
    {
        set(i,v,0,0,size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r) return sums[x];

        ll m = (lx+rx)/2;
        ll s1 = sum(l,r,x*2+1, lx, m);
        ll s2 = sum(l,r,x*2+2, m, rx);
        return s1+s2;
    }

    ll sum(ll l, ll r)
    {
        return sum(l,r,0,0,size);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    vector <ll> a(st.size);
    for (ll i = 0; i < st.size; ++i)
    {
        a[i]=0;        
    }
    st.build(a);
    while(m--)
    {
        ll op;
        cin >> op;
        if (op==1)
        {
            ll l,r,v;
            cin >> l >> r >> v;
            st.set(l,v);
            // for (int i = 0; i < st.sums.size(); ++i)
            // {
            //     cout << st.sums[i] << " ";
            //     // printf("%lld ",st.sums[i] );
            //     // printf("%d\n",i );
            // }
            // cout << '\n';
            if (r<n)
                st.set(r,-v);
            // for (int i = 0; i < st.sums.size(); ++i)
            // {
            //     cout << st.sums[i] << " ";
            //     // printf("%lld ",st.sums[i] );
            //     // printf("%d\n",i );
            // }
            // cout << '\n';
        }
        else
        {
            ll i;
            cin >>i ;
            cout << st.sum(0,i+1) << '\n';
        }
    }
  
    return 0;
}
