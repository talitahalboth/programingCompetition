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

struct segtree 
{
    int size;
    vector<ll> minimum;

    void init(int n)
    {
        size=1;
        while(size<n)
            size*=2;
        minimum.assign(2*size, iinf);

    }
    void build(vector<ll> &a, int x, int lx, int rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
                minimum[x] = a[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        minimum[x] = min(minimum[2*x+1], minimum[2*x+2]);
    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx-lx==1)
        {
            minimum[x]=v;
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
        minimum[x] = min(minimum[2*x+1],minimum[2*x+2]);
    }
    void set(int i, int v)
    {
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return iinf;
        if (lx >= l && rx <= r) return minimum[x];

        int m = (lx+rx)/2;
        ll s1 = sum(l,r,x*2+1, lx, m);
        ll s2 = sum(l,r,x*2+2, m, rx);
        return min(s1,s2);
    }

    ll sum(int l, int r)
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
            cout << st.sum(l,r) << '\n';
        }
    }
  
    return 0;
}
