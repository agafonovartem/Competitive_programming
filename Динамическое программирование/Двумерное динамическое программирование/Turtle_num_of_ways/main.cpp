#include <iostream>
#include <vector>
using namespace std;
const long MOD_VAL = 1000000000 + 9;

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
    
    vector<vector <long long>> a(n + 1, vector<long long> (m + 1));
    vector<vector <long long>> dp(n + 1, vector<long long> (m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 0){
                dp[i][j] = Madd(Madd(dp[i-1][j],
                                     dp[i][j-1],
                                     MOD_VAL),
                                dp[i-1][j-1],
                                MOD_VAL);
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    
    
    
    
    
    return 0;
}
