#include <iostream>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <cmath>
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

int calculateNewIx(int ix, int k, int size)
{
    return (ix + k) % size;
}

void rotate(vector<int>& nums, int k) {
    int count = 0;
    int ini = 0;
    int prev = nums[ini];
    int prevIx = ini;
    nums[ini] = nums[(nums.size()*2 - k + ini ) % nums.size()];
    while(count < nums.size())
    {
        int ix = calculateNewIx(prevIx, k, nums.size());
        int tmp = nums[ix];
        nums[ix] = prev;
        prevIx = ix;
        prev = tmp;
        count+=1;
        if (prevIx == ini && count < nums.size())
        {
            ini+=1;
            prev = nums[ini];
            prevIx = ini;
            nums[ini] = nums[(nums.size()*2 - k - ini ) % nums.size()];

        }
    } 
}

int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    {
        vector<int> n {
           -1,-100,3,99
        };
        rotate(n, 2);
        for (int i = 0; i < n.size(); i++)
        {
            cout << n[i] << endl;
        }
        
        
    }
    return 0;
}