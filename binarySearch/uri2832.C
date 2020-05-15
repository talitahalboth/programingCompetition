#include <bits/stdc++.h>
#define MAX 1e8
using namespace std;
vector <long long> ciclos;
int main(int argc, char const *argv[])
{
    long long n,f;
    cin >> n >> f;
    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        ciclos.push_back(x);
    }
    long long inf = 0;
    long long sup = (int)MAX;
    while (sup-inf > 1)
    {
        long long mid = (sup+inf)/2;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += mid/ciclos[i];
        }
        if (sum < f)
            inf = mid;
        else
            sup = mid;
        //cout << inf << " " << mid << " " << sup << " " <<sum << endl;
    }
    cout << sup << endl;
    return 0;
}
