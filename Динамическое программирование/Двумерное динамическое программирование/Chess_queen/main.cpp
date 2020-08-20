#include <iostream>
#include <vector>
using namespace std;
const long MOD_VAL = 1000000000 + 7;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}




int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector <long long>> dp;
    vector<vector <long long>> dp_row;
    vector<vector <long long>> dp_col;
    vector<vector <long long>> dp_diag;
    vector<vector <long long>> a;
    
    dp.assign(n + 1, vector<long long> (m + 1, 0));
    
    dp_row.assign(n + 1, vector<long long> (m + 1, 0));
    dp_col.assign(n + 1, vector<long long> (m + 1, 0));
    dp_diag.assign(n + 1, vector<long long> (m + 1, 0));
    // вместо этих матриц можно вообще  хранить 2 вектора, тк при
    // при рассчете dp[i][j] нам мужны лишь значения на
    // строке [i-1] и столбце [j-1]
    
    
    for (int k = 1; k <= n + m - 1; k++){
        for (int i = min(k, n), j = max(1, k - n + 1); i >= 1 && j <= m; i--, j++){
            if (i == 1 && j == 1){
                dp[i][j] = 1;
                dp_row[i][j] = 1;
                dp_col[i][j] = 1;
                dp_diag[i][j] = 1;
            } else{
                dp[i][j] = Madd(Madd(dp_row[i - 1][j], dp_col[i][j - 1], MOD_VAL),
                                dp_diag[i - 1][j - 1],
                                MOD_VAL);
                dp_row[i][j] = Madd(dp_row[i - 1][j], dp[i][j], MOD_VAL);
                dp_col[i][j] = Madd(dp_col[i][j - 1], dp[i][j], MOD_VAL);
                dp_diag[i][j] = Madd(dp_diag[i - 1][j - 1], dp[i][j], MOD_VAL);
            }
        }
    }
    
    
    cout << dp[n][m] << endl;
    
    
    return 0;
}


