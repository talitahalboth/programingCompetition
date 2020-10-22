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

#define MAX 412345

struct segtree 
{
    int size;
    vector<int> minimum;

    void init(int n)
    {
        size=1;
        while(size<n)
            size*=2;
        // if (2*size > 10*MAX)
        // {
        //     cout << size << endl;
        //     cout << "erro"<<endl;
        //     exit (0);
        // }
        // for (int i = 0; i < 2*size; ++i)
        // {
        //     if (i >= 10*MAX)
        //         exit (0);
        //     minimum[i] = iinf;
        // }
        minimum.assign(2*size, iinf);

    }
    void build(ll a[], int x, int lx, int rx, int tam)
    {
        if (rx-lx == 1)
        {
            if (lx < (int)tam)
                minimum[x] = a[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1, lx, m, tam);
        build(a,2*x+2, m, rx, tam);
        minimum[x] = min(minimum[2*x+1], minimum[2*x+2]);
    }

    void build(ll a[], int tam)
    {
        build(a, 0, 0, size, tam);
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

    ll minim(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return iinf;
        if (lx >= l && rx <= r) return minimum[x];

        int m = (lx+rx)/2;
        ll s1 = minim(l,r,x*2+1, lx, m);
        ll s2 = minim(l,r,x*2+2, m, rx);
        return min(s1,s2);
    }

    ll minim(int l, int r)
    {
        return minim(l,r,0,0,size);
    }
};


int p[MAX];
int c[MAX];
int lcp[MAX];
int cnew[MAX];
pair<char,int> a1[MAX];
pair <pii, int> a[MAX];

int bucketFir[MAX];
int countFir[MAX];
int posIni[MAX];
void countSort(int p[], int c[], int n)
{
    memset(countFir,0,sizeof countFir);
    for (int i = 0; i < n; ++i)
        countFir[c[i]]++;
    posIni[0]=0;
    for (int i = 1; i < n; ++i)
        posIni[i] = posIni[i-1] + countFir[i-1];

    for (int i = 0; i < n; ++i)
        bucketFir[posIni[c[p[i]]]++] = p[i];

    for (int i = 0; i < n; ++i)
        p[i] = bucketFir[i];


}

void suffixArray(string &s, int n)
{

    for (int i = 0; i < n; ++i)
        a1[i] = {s[i], i};
    sort(a1, a1+n);
    for (int i = 0; i < n; ++i)
        p[i] = a1[i].se;
    c[p[0]]=0;
    for (int i = 1; i < n; ++i)
    {
        if (a1[i].fi == a1[i-1].fi)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]]+1;
    }

    int k = 0;
    while ((1<<k) < n)
    {
        for (int i = 0; i < n; ++i)
            p[i] = (p[i] - (1<<k)+n)%n;

        countSort(p,c,n);

        cnew[p[0]]=0;
        int last=0;
        for (int i = 1; i < n; ++i)
        {
            pii prev = {c[p[i-1]], c[(p[i-1] + (1<<k)) % n]};
            pii now = {c[p[i]], c[(p[i] + (1<<k)) % n]};

            if (now == prev)
                cnew[p[i]] = cnew[p[i-1]];
            else
                cnew[p[i]] = cnew[p[i-1]]+1;
            
            last = cnew[p[i]];
        }
        for (int i = 0; i < n; ++i)
            c[i]=cnew[i];

        if (last==n-1)
        {
            return ;
        }
        k++;
    }
}
void buildLCPArray(string &s, int n)
{
        // number of chars that we know are equal
    int k = 0;
    for (int i = 0; i < n-1; ++i)
    {
        // pos of suffix i in the suff array
        int pi = c[i];
        int j = p[pi - 1];
        // lcp[i] = lcp(s[i..], s[j..])
        while(s[i+k]==s[j+k]) 
            k++;
        // printf("%d\n",k );

        lcp[pi]=k;
        k = max(k-1,0);
    }
}
void printPair(pii p)
{
    cout << p.fi << " " << p.se;
}
segtree st;
// return true if p1 < p2
bool compare(pii p1, pii p2)
{
    if (p1 == p2)
        return true;
    if (p1.fi == p2.fi)
    {
        // smalles wins
        if (p1.se <= p2.se)
            return true;
        return false;
    }
    int sizeP1 = p1.se - p1.fi + 1;
    int sizeP2 = p2.se - p2.fi + 1;
    int p1i = c[p1.fi];
    int p2i = c[p2.fi];


    int mini = st.minim(min(p1i, p2i)+1, max(p1i, p2i)+1);


    // if the number of equal prefix is bigger than the size of the smallest
    // means the smallest should come first
    //if they have the same length, smallest l first, if l is equal smalles r
    if (mini >= min(sizeP1, sizeP2))
    {
        if (sizeP1 < sizeP2)
            return true;
        if (sizeP2 < sizeP1)
            return false;
        if (p1.fi < p2.fi)
            return true;
        if (p2.fi < p1.fi)
            return false;

        return true;
    }
    if (p1i < p2i)
        return true;
    return false;

}
pii substr[MAX];
ll v[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    s.pb(2);
    int n = s.size();
    suffixArray(s,n);
    buildLCPArray(s,n);

    st.init(n);
    // vector <ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        // cout << p[i] << " " <<c[i]<< endl;
        v[i] = lcp[i];        
    }

    st.build(v,n);
    int m;
    cin >> m;
    // vector<pii> substr;
    for (int i = 0; i < m; ++i)
    {
        int l,r;
        cin >> l >> r;
        substr[i] = mp(l-1, r-1);
        // substr.pb(mp(l-1,r-1));
    }
    sort(substr, substr+m, compare);
    for (int i = 0; i < m; ++i)
    {
        cout << substr[i].fi+1 << " " <<substr[i].se+1 << endl;
    }

  
    return 0;
}

