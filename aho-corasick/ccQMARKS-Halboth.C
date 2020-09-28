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


const int K = 26;
int sz=0;
struct Vertex {
    int next[K];
    int leaf = -1;
    // ancestor
    int p = -1;
    // character of the ancestor
    char pch;
    // suffix link
    int link = -1;
    int exit = -1;
    int go[K];

    int val=0;
    string s;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

// map <string, int> m;
// map <int, string> m2;
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].val++;
    t[v].leaf = sz++;
    t[v].s=s;

}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        
    }
       
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int getExit(int v)
{
    if(t[v].exit==-1){
        int u=get_link(v);
        if(u!=0 && t[u].leaf!=-1) t[v].exit=u; 
        else t[v].exit = v==0 ? 0 : getExit(u);
    }
    return t[v].exit;
}

string s;
int dp[1123][1123];

int pd(int letter, int pos)
{
	if (letter> s.size())
		return 0;

	if (dp[letter][pos]!=-1)
		return dp[letter][pos];

	int tmp = 0;
	if (t[pos].leaf!=-1)
		tmp+=t[pos].val;
    int v2 =getExit(pos);

    while (v2 != 0 && v2 != -1)
    {
		tmp+=t[v2].val;
        v2 =getExit(v2);
    }
    if (letter < s.size())
    {
    	if (s[letter]=='?')
    	{
    		int maxRes = 0;
    		for (int i = 0; i < 26; ++i)
    		{
    			char letra = 'a'+i;
    			s[letter]=letra;
    			int res = pd(letter+1, go(pos, letra));
    			if (res > maxRes)
    				maxRes = res;
    			s[letter]='?';
    		}
    		dp[letter][pos] = maxRes + tmp;

    	}
    	else
    		dp[letter][pos] = tmp + pd(letter+1, go(pos, s[letter]));
    }
    else
    	dp[letter][pos] = tmp;
	return dp[letter][pos];

}
string ans;
int reconstructString(int letter, int pos)
{
	if (letter == s.size())
		return 0;
	
	if (s[letter]!='?')
		ans.pb(s[letter]);
	else
	{
		int max=-1;
		char letra=0;
		for (int i = 0; i < 26; ++i)
		{
			int tmp = pd(letter+1, go(pos, i+'a'));
			if (tmp > max)
			{
				max = tmp;
				letra = i+'a';
			}
			
		}
		ans.pb(letra);
	}
	reconstructString(letter+1, go(pos, ans.back()));
}
int main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
 	int cases;
 	cin >> cases;
 	while (cases--)
 	{
 		ans.clear();
 		for (int i = 0; i < 1123; ++i)
 		{
 			for (int j = 0; j < 1123; ++j)
 			{
 				dp[i][j]=-1;
 			}
 		}
 		// for (int i = 0; i < 1123; ++i)
 		// 	memset(dp[i], -1, sizeof(dp[i]));
 		t.clear();
 		t.emplace_back();
 		int n,m;
 		cin >> n >> m;
 		
 		cin >> s;
 		for (int i = 0; i < m; ++i)
 		{
 			string str;
 			cin >> str;
 			add_string(str);
 		}
 		cout << pd(0,0) << endl;
 		// // printf("%d\n",pd(0,0) );
 		reconstructString(0,0);
 		cout << ans << endl;

 	}
  
	return 0;
}
