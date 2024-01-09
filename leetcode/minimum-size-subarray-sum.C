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


int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0;
    int j = 0;
    int minn = iinf;
    int currSum = 0;
    while(i != nums.size())
    {
        while (currSum < target && j < nums.size())
        {
            currSum+=nums[j];
            j+=1;
        }
        cout << "i: "<< i << ", j: "<< j << " " << currSum<< endl;
        if (currSum >= target)
        {
            while(currSum >= target && i < nums.size() && i <= j)
            {
                currSum-=nums[i];
                i++;
            }
            cout << i << " " << j << endl;
            minn=min(minn, j-i+1);
        }
        if (j < nums.size()) {
            currSum+=nums[j];
            j++;
        }
        else if (i < nums.size())
        {
            currSum-=nums[i];
            i++;
        }
    }
    return minn;

    
}


int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    
    vector<int> n {
        1,4,4
    };
    cout << minSubArrayLen(4, n);
    return 0;
}