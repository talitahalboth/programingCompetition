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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    s.pb('$');
    int n = s.size();
    suffixArray(s,n);
    buildLCPArray(s,n);
    
    for (int i = 0; i < n; ++i)
    {
        cout <<lcp[i] <<" " << p[i] <<" " << s.substr(p[i], n-p[i]);
        cout << '\n';
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout <<p[i] <<" ";
    // }
    // cout << endl;
    // for (int i = 1; i < n; ++i)
    // {
    //     cout <<lcp[i] <<" ";
    // }
    // cout << endl;
  
    return 0;
}

