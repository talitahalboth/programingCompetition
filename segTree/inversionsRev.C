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
#define pll pair<ll, ll>
using namespace std;

struct item
{
    ll i;
    
};

struct segtree 
{
    ll size;
    vector<item> value;

    item NEUTRAL_ELEM = {0};
    void init(ll n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        return {a.i+b.i};
    }

    item single(ll v)
    {
        return {v};
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

    void set(ll i,ll v, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            value[x] = single(v);
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

    int find(ll k, ll x, ll lx, ll rx)
    {
        if (rx-lx==1)
        {
            if (value[x].i)
            {
                return (x - (size-1));
            }
            else return 0;
        }

        ll m = (lx+rx)/2;
        if (value[x*2+1].i > k)
        {
            return find(k,x*2+1,lx,m);
            //vai pra esquerda
        }
        else
        {
            k = k - value[x*2+1].i;
            return find(k,x*2+2,m,rx);
            //vai pra direita
        }
    }

    int find(ll k)
    {
        return find(k,0,0,size);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n;

    segtree st;
    st.init(n);
    vector<ll>b;
    b.assign(n,1LL);
    st.build(b);

    vector <ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];        
    }
    int count=n;
    vector<int> res;
    for (int i = n-1; i >= 0; --i)
    {
        int kth = a[i];
        // printf("%d: ",kth );
        kth = count - (kth+1);
        count--;
        // printf("%d\n",kth );
        int ans = st.find(kth);
        res.pb(ans+1);
        // printf("ans: %d\n",ans+1 );
        st.set(ans,0);
    }
    reverse(all(res));
    for(auto v: res)
        printf("%d ",v );
    printf("\n");
  
    return 0;
}
