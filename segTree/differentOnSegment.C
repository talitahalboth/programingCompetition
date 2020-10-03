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
struct item
{
    ll dif;
    vector<int> numbers;
    
};

struct segtree 
{
    ll size;
    vector<item> value;
    vector<int> tmp;
    item NEUTRAL_ELEM = {0,tmp };
    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        int different = a.dif;
        for (int i = 0; i < b.numbers.size(); ++i)
        {
            int isDif=1;
            for (int j = 0; j < a.numbers.size(); ++j)
            {
                if (b.numbers[i] == a.numbers[j])
                {
                    isDif=0;
                    break;
                }
            }
            if (isDif)
            {
                a.numbers.pb(b.numbers[i]);
                a.dif++;
            }
        }
        return a;
    }

    item single(ll v)
    {
        vector<int> ans;
        ans.pb(v);

        return {1,ans};
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

    item sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEM;
        if (lx >= l && rx <= r) return value[x];

        ll m = (lx+rx)/2;
        item s1 = sum(l,r,x*2+1, lx, m);
        item s2 = sum(l,r,x*2+2, m, rx);
        return merge(s1,s2);
    }

    item sum(ll l, ll r)
    {
        return sum(l,r,0,0,size);
    }
};

int imprimeItem(item it)
{
    printf("%lld\n",it.dif );
    for (int i = 0; i < it.numbers.size(); ++i)
    {
        printf("%d ",it.numbers[i] );
    }
    printf("\n");
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> a;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.pb(x);        
    }
    segtree st;
    st.init(n);
    st.build(a);
    for (int i = 0; i < m; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r;
            cin >> l >> r;
            printf("%lld\n",st.sum(l-1, r).dif );
        }
        else
        {
            int k,v;
            cin >> k >> v;
            st.set(k-1,v);
        }
    }
    return 0;
}
