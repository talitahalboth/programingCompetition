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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    vector<int> tmp;
    while (i < m || j < n)
    {
        if (i >= m) {
            while (j < n)
            {
                tmp.push_back(nums2[j++]);
            }
        }
        else if (j >= n) {
            while (i < m)
            {
                tmp.push_back(nums1[i++]);
            }
        }
        else {
            if (nums1[i] <= nums2[j])
            {
                tmp.push_back(nums1[i++]);
            }
            else 
            {
                tmp.push_back(nums2[j++]);
            }
        }
    }
    for (int i = 0; i < n+m; i++)
    {
        nums1[i] = tmp[i];
    }
}
int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int>nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int>nums2 = {2,5,6};
    int n = 3;
    merge(nums1, m, nums2, n);
    for(int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << endl;
    }
    return 0;
}