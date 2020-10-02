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
typedef ll item;
// struct item
// {
//     ll i;
    
// };

int visited[112345];

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

    void update(int k, int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return;
        if (lx >= l && rx <= r)
        {
            value[x]+=k;
            return;
        }

        int m = (lx+rx)/2;
        update(k,l,r,x*2+1, lx, m);
        update(k,l,r,x*2+2, m, rx);
    }
    void update(int k, int l, int r)
    {
        update(k,l,r,0,0,size);
    }
    ll getSum(int i, int x, int lx, int rx)
    {
        if (lx > i || i >= rx)
            return NEUTRAL_ELEM;
        if (rx - lx == 1)
        {
            // printf("%d %d\n",x,value[x] );
            return value[x];
        }
        ll ret=0;
        if (lx <= i && rx >= i)
            ret+=value[x];
        int m = (lx+rx)/2;
        ret+=getSum(i,x*2+1, lx, m);
        ret+=getSum(i,x*2+2, m, rx);
        // printf("i:%d\n",i );
        // printf("%d\n",value[x] );
        // printf("%d %d %d\n",lx,rx,ret );
        return ret;

    }
    ll getSum(int i)
    {
        return getSum(i, 0, 0, size);
    }
};

pii borders[112345];
queue<int>b;
int contaIntersect[112345];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; ++i)
    {
        st.set(i,0);
    }
    for (int i = 0; i < m; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r,k;
            cin >> l >> r >> k;
            st.update(k,l,r);
        }
        else
        {
            int j;
            cin >> j;
            printf("%lld\n",st.getSum(j) );
        }
        
    }
    

    return 0;
}
