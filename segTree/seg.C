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
    int m, c;
    
};

struct segtree 
{
    int size;
    vector<item> value;

    item NEUTRAL_ELEM = {iinf, 0};
    void init(int n)
    {
        size=1;
        while(size<n)
            size*=2;
        value.resize(2*size);

    }
    item merge(item a, item b)
    {
        if (a.m < b.m) return a;
        if (a.m > b.m) return b;
        return{a.m, a.c+b.c};
    }

    item single(int v)
    {
        return {v, 1};
    }
    void build(vector<ll> &a, int x, int lx, int rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
            {
                value[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        value[x] = merge(value[2*x+1],  value[2*x+2]);

    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
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
    void set(int i, int v)
    {
        set(i,v,0,0,size);
    }

    item sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return NEUTRAL_ELEM;
        if (lx >= l && rx <= r) return value[x];

        int m = (lx+rx)/2;
        item s1 = sum(l,r,x*2+1, lx, m);
        item s2 = sum(l,r,x*2+2, m, rx);
        return merge(s1,s2);
    }

    item sum(int l, int r)
    {
        return sum(l,r,0,0,size);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    vector <ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];        
    }
    st.build(a);
    while(m--)
    {
        int op;
        cin >> op;
        if (op==1)
        {
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            item ans = st.sum(l,r);
            cout << ans.m << " " <<ans.c << '\n';
        }
    }
  
    return 0;
}
