#include <iostream>
#include <vector>
using namespace std;
const long MOD_VAL = 1000000000 + 123;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}

vector<vector <long long>> dp;

long long f(int i, int j, int n, int m){
    if (i == 1 && j == 1 ){
        return 1;
    } else if (i <= 0 || j <= 0 || i > n || j > m){
        return 0;
    }
    
    if (dp[i][j] != -1){
        return dp[i][j];
    } else{
        dp[i][j] = Madd(Madd(f(i - 1, j - 2, n, m), f(i - 2, j - 1, n, m), MOD_VAL),
                        Madd(f(i + 1, j - 2, n, m), f(i - 2, j + 1, n, m), MOD_VAL),
                        MOD_VAL);
        return dp[i][j];
    }
}

// перебор по диагонали
/*
for (int k = 1; k < n + m - 1; k++){
    for (int i = min(k, n - 1), j = max(k - n + 1, 0); i >= 0 && j < m; --i, ++j){
    }
}*/

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    dp.assign(n + 1, vector<long long> (m + 1, -1));

    cout << f(n, m, n, m) << endl;
    
    return 0;
}
