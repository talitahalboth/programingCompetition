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
int p[MAX];
int c[MAX];
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

void suffixArray(string s, int n)
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

void imprimeP(string s, int index)
{
    int n = s.size()/2;
    for (int i = 0; i < n; ++i)
    {
        int ix = (p[index]+i) ;
        cout << s[ix];
    }
    cout << endl;
}

int compareStr(string s, int index, string s2)
{
    // imprimeP(s2, index);
    int n = s2.size();
    for (int i = 0; i < s.size(); ++i)
    {
        if (s2[(p[index]+i)]<s[i])
            return -1;
        else if (s2[(p[index]+i)]>s[i])
            return 1;
    }
    return 0;
}

int bbFirstSmaller(string &s, string &s2)
{
    int inf=0, sup=s2.size()/2 -1;
    int mid,ans=-1;
    while (sup >= inf)
    {
        mid = inf + (sup-inf)/2;
        int cmp = s2.compare(p[mid], s.size(), s);
        if (cmp < 0)
        {
            ans=mid;
            inf = mid+1;
        }
        else if (cmp >= 0)
            sup = mid-1; 
    }
    return (ans);
}

int bbFirstGreater(string &s, string &s2)
{
    int inf=0, sup=s2.size()/2 -1;
    int mid,ans=-1;
    while (sup >= inf)
    {
        mid = inf + (sup-inf)/2;
        int cmp = s2.compare(p[mid], s.size(), s);
        if (cmp <= 0)
        {
            inf = mid+1;
        }
        else if (cmp > 0)
        {
            ans=mid;
            sup = mid-1; 
        }
    }
    return (ans);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    s.pb('$');
    int n = s.size();
    suffixArray(s,n);
    s +=s;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string s2;
        cin >> s2;
        int a1 = bbFirstSmaller(s2,s);
        int a2 = bbFirstGreater(s2,s);
        if (a1==-1 || a2==-1)
        {
            a1=max(a1,a2);
            cout << s.size()/2 -a1-1 << endl;
        }
        else
        {
            cout << a2 - a1 - 1 << endl;
            
        }
    }
  
    return 0;
}

