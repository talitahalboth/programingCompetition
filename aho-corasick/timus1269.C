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

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int K = 256;

struct Vertex {
    int next[K];
    bool leaf = false;
    // ancesrtor
    int p = -1;
    // character of the ancestor
    char pch;
    // suffix link
    int link = -1;
    int exit = -1;
    int go[K];

    Vertex(int p=-1, char ch=0) : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

map <string, int> m;
map <int, string> m2;
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch;
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    m[s] = v;
    m2[v] = s;
    t[v].leaf = true;

}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        
        int u = t[v].link;
        while(u!= 0)
        {
            if (t[u].leaf)
            {
                t[v].exit = u;
                break;
            }
            u = t[u].link;
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch;
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

// set <string> visitados;
map <string, int> visitados;
vector <int> positions;
void percorreArvore(string s)
{
    int v = 0;
    positions.clear();
    for (int i = 0; i < s.size(); ++i)
    {
        int u = s[i];
        // se o nó em que estou tem filho s[i]
        if (t[v].next[u]!= -1)
        {
            v = t[v].next[u];
            if (t[v].leaf)
            {
                if (!visitados[m2[v]])
                    positions.pb((i+1) - m2[v].size()+1);
                visitados[m2[v]]=1;
            }
            int v2 = t[v].exit;
            while (v2 != -1)
            {
                
                if (!visitados[m2[v2]])
                    positions.pb((i+1) - m2[v2].size()+1);
                visitados[m2[v2]]=1;
                v2 = t[v2].exit;
            }
        }
        else
        {
            while (t[v].next[u]== -1 && v!=0)
                v = t[v].link;
            if (t[v].next[u] != -1)
                v = t[v].next[u];
            if (t[v].leaf)
            {
                if (!visitados[m2[v]])
                    positions.pb((i+1) - m2[v].size()+1);
                visitados[m2[v]]=1;
            }
            int v2 = t[v].exit;
            while (v2 != -1)
            {
                
                if (!visitados[m2[v2]])
                    positions.pb((i+1) - m2[v2].size()+1);
                visitados[m2[v2]]=1;
                v2 = t[v2].exit;
            }

        }
    }

}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        add_string(str);
    }
    for (int i = 0; i < t.size(); ++i)
    {
        get_link(i);
    }
    int m;
    cin >> m;
    string str;
    getline(cin, str);  
    int conta = 0;  
    for (int i = 1; i <= m; ++i)
    {
        getline(cin, str);
        percorreArvore(str);
        // cout << i << endl;
        // cout << str<<endl;
        if (positions.size() > 0)
        {
            conta =1;
            for (int j = 0; j < positions.size(); ++j)
            {
                printf("%d %d\n",i , positions[j] );
                
            }
        }

    }
    if (!conta)
        printf("Passed\n");

    return 0;
}