#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n;
int k;
int buscaBinaria()
{
    int inf = 0;
    int sup = n;
    while (inf < sup)
    {
        int mid = (sup+inf)/2;
        int tempo = 0;
        for (int i = 0; i <= mid+1; ++i)
        {
            tempo += i*5;
        }
        if (tempo <= k)
            inf = mid+1;
        else
            sup = mid;

    }
    return inf;
}
int main(){
    scanf ("%d %d", &n, &k);
    k = 60*4 - k;
    printf("%d\n", buscaBinaria()); 
    return 0;
}