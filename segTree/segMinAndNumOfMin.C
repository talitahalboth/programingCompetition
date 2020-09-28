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

struct segtree 
{
    int size;
    vector<pll> numberMinimum;

    void init(int n)
    {
        size=1;
        while(size<n)
            size*=2;
        numberMinimum.assign(2*size, mp(iinf, 1));

    }
    void build(vector<ll> &a, int x, int lx, int rx)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)a.size())
            {
                numberMinimum[x].fi = a[lx];
                numberMinimum[x].se = 1;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1, lx, m);
        build(a,2*x+2, m, rx);
        numberMinimum[x].fi = min(numberMinimum[2*x+1].fi, numberMinimum[2*x+2].fi);
        if (numberMinimum[2*x+1].fi == numberMinimum[2*x+2].fi)
            numberMinimum[x].se = numberMinimum[2*x+1].se + numberMinimum[2*x+2].se;
        else if (numberMinimum[2*x+1].fi < numberMinimum[2*x+2].fi)
            numberMinimum[x].se = numberMinimum[2*x+1].se;
        else
             numberMinimum[x].se = numberMinimum[2*x+2].se;
    }

    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx-lx==1)
        {
            numberMinimum[x].fi=v;
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
        numberMinimum[x] = min(numberMinimum[2*x+1],numberMinimum[2*x+2]);
        if (numberMinimum[2*x+1].fi == numberMinimum[2*x+2].fi)
            numberMinimum[x].se = numberMinimum[2*x+1].se + numberMinimum[2*x+2].se;
        else if (numberMinimum[2*x+1].fi < numberMinimum[2*x+2].fi)
            numberMinimum[x].se = numberMinimum[2*x+1].se;
        else
             numberMinimum[x].se = numberMinimum[2*x+2].se;
    }
    void set(int i, int v)
    {
        set(i,v,0,0,size);
    }

    pll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return mp(iinf,1);
        if (lx >= l && rx <= r) return numberMinimum[x];

        int m = (lx+rx)/2;
        pll s1 = sum(l,r,x*2+1, lx, m);
        pll s2 = sum(l,r,x*2+2, m, rx);
        if(s1.fi==s2.fi)
            return mp(s1.fi, s1.se+s2.se);
        if (s1.fi < s2.fi)
            return s1;
        return s2;
    }

    pll sum(int l, int r)
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
            pll ans = st.sum(l,r);
            cout << ans.fi << " " <<ans.se << '\n';
        }
    }
  
    return 0;
}
