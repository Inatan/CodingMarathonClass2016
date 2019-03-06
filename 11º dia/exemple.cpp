

/**********ALLAH IS ALMIGHTY************/

/**
 uva online judge;
 problem name :: Modular Fibonacci;
 problem id   :: 10229;
 catagory     :: matrix_exponential;
 my solution ............................
**/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef long long sll;

sll mod;

struct matrix {
 sll row , col;
 sll tb[23][23];
};

matrix multiply (matrix a , matrix b) {
 assert (a.col == b.row);
 matrix ret;
 ret.row = a.row;
 ret.col = b.col;
 for (sll i = 0; i < ret.row; i++) {
        for (sll j = 0; j < ret.col; j++) {
            sll sum = 0;
            for (sll k = 0; k < a.col; k++) {
                sum += a.tb[i][k] * b.tb[k][j];
                sum %= mod;
            }
            ret.tb[i][j] = sum;
        }
 }
 return ret;
}

matrix expo (matrix n , sll p) {
    assert (p >= 1);
    if (p == 1) return n;
    if (p % 2 == 0) {
        matrix res = expo (n , p / 2);
        return multiply (res , res);
    }
    else return multiply (n , expo (n , p - 1));
}

int main () {
 sll n , m;
 while (scanf ("%lld%lld" , &n , &m) == 2) {
        mod = (1<<m);
        if (n == 0) cout << "0" << endl;
        else if (n == 1) cout << 1 % mod << endl;
        else if (n == 2) cout << 1 % mod << endl;
        else {
            matrix bm;
            bm.row = bm.col = 2;
            bm.tb[0][0] = bm.tb[0][1] = 1;
            bm.tb[1][0] = 1; bm.tb[1][1] = 0;
            matrix rr = expo (bm , n - 2);
            matrix bc; bc.col = 1; bc.row = 2;
            bc.tb[0][0] = 1;
            bc.tb[1][0] = 1;
            matrix ans = multiply (rr , bc);
            sll result = ans.tb[0][0] % mod;
            cout << result << endl;
        }
 }
}

