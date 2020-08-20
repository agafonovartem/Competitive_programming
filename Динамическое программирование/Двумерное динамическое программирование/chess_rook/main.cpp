#include <iostream>
#include <vector>
using namespace std;
const long MOD_VAL = 1000000000 + 33;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}



/*
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector <long long>> dp;
    vector<vector <long long>> dp_row;
    vector<vector <long long>> dp_col;
    vector<vector <long long>> a;
    
    dp.assign(n + 1, vector<long long> (m + 1, 0));
    dp_row.assign(n + 1, vector<long long> (m + 1, 0));
    dp_col.assign(n + 1, vector<long long> (m + 1, 0));
    
    
    
    
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1){
                dp[i][j] = 1;
                dp_row[i][j] = 1;
                dp_col[i][j] = 1;
            } else{
                dp[i][j] = Madd(dp_row[i - 1][j], dp_col[i][j - 1], MOD_VAL);
                dp_row[i][j] = Madd(dp_row[i - 1][j], dp[i][j], MOD_VAL);
                dp_col[i][j] = Madd(dp_col[i][j - 1], dp[i][j], MOD_VAL);
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    
    return 0;
}
*/


// заметим, что dp_row = dp_col ^ T, попробуем переписать, импользуя меньше памяти
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector <long long>> dp;
    vector<vector <long long>> dp_sum; // вместо нее можно вообще  хранить 2 вектора, тк при
                                      // при рассчете dp[i][j] нам мужны лишь значения на
                                     // строке [i-1] и столбце [j-1]
    vector<vector <long long>> a;
    
    
    int nm = max(m, n);
    dp.assign(n + 1, vector<long long> (m + 1, 0));
    dp_sum.assign(nm + 1, vector<long long> (nm + 1, 0));

     
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1){
                dp[i][j] = 1;
                dp_sum[i][j] = 1;
            } else{
                dp[i][j] = Madd(dp_sum[i - 1][j], dp_sum[j - 1][i], MOD_VAL);
                if (dp_sum[i][j] == 0){
                    dp_sum[i][j] = Madd(dp_sum[i - 1][j], dp[i][j], MOD_VAL);
                }
                if (dp_sum[j][i] == 0){
                    dp_sum[j][i] = Madd(dp_sum[j - 1][i], dp[i][j], MOD_VAL);
                }
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    
    return 0;
}
