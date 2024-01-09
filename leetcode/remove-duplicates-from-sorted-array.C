#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (ll (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (ll (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (ll (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define unicos(X) (X).erase(unique(all(X)),(X).end())
#define NL <<"\n"
#define EPS 1e-6
#define MOD 1000000007
#define dijkstra  0x3f3f3f3f
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
#define int long long
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int inf = 0x3f3f3f3f;
    int count = 0;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] == nums[i-1])
        {
            nums[i] = inf;
            count++;

        }
    }
    sort(nums.begin(), nums.end());

    return nums.size() - count;
}
int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    {
        vector<int> n {0,0,1,1,1,2,2,3,3,4};
        int res = removeDuplicates(n);
        cout << res << endl;
        for (int i  = 0; i < res ; i++)
        {
            cout << n[i] <<  " ";
        }
        cout  << endl;
    }
    return 0;
}