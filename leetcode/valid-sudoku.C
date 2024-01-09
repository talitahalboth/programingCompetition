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
#define NL <<'\n'
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


bool isValidSudoku(vector<vector<char>>& board) {
    int primes[10] = {2,3,5,7,11,13,17,19,23,29};
    for (int i = 0; i < 9; i++)
    {
        int mulCol = 1;
        int mulRow = 1;
        int mulCell = 1;
        for(int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int a = board[i][j] - '0';
                if (mulCol % primes[a] == 0) {
                    return false;
                }
                mulCol*=primes[a];
            }
            if (board[j][i] != '.')
            {
                int a = board[j][i] - '0';
                if (mulRow % primes[a] == 0)  {
                    return false;
                }
                mulRow*=primes[a];
            }
            int i2 = (i/3)*3 + (j/3);
            int j2 = (i % 3)*3 + j%3;
            if (board[i2][j2] != '.')
            {
                int a = board[i2][j2] - '0';
                if (mulCell % primes[a] == 0)  {
                    return false;
                }
                mulCell*=primes[a];
            }
        }
    }
    return true;
        
}


int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(0);
    
    vector<vector<char>> n {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << (isValidSudoku(
        n
        ) == true ? "true" : "false");
    return 0;
}