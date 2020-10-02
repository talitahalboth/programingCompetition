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
        return sum(l,r,0,0,size);
    }
};

pii borders[112345];
queue<int>b;
int contaIntersect[112345];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    segtree st;
    st.init(2*n);
    for (int i = 0; i < 2*n; ++i)
    {
        st.set(i,0);
    }
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; ++i)
    {
        cin >> a[i];
        if (!visited[a[i]])
        {
            b.push(a[i]);
            visited[a[i]]=1;
            borders[a[i]].fi=i;
            st.set(i,1);
        }
        else
        {
            borders[a[i]].se=i;
            st.set(borders[a[i]].fi,0);
            contaIntersect[a[i]] += st.sum(borders[a[i]].fi, borders[a[i]].se);            
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        visited[i]=0;
        borders[i]={0,0};
    }

    for (int i = 2*n -1 ; i >= 0; --i)
    {
        if (!visited[a[i]])
        {
            b.push(a[i]);
            visited[a[i]]=1;
            borders[a[i]].fi=i;
            st.set(i,1);
        }
        else
        {
            borders[a[i]].se=i;
            st.set(borders[a[i]].fi,0);
            contaIntersect[a[i]] += st.sum(borders[a[i]].se,borders[a[i]].fi);            
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ",contaIntersect[i] );
    }
    printf("\n");  
    return 0;
}
