#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;
vector<long long> dpsum;
const long long MOD_VAL = 1000000000+7;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}

long long Msub(long long a, long long b, long long MOD){
    return  Mnorm(Mnorm(a, MOD) - Mnorm(b, MOD), MOD);
}



int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    
    dp.resize(n + 1);
    dpsum.resize(n + 1);
    
    string s;
    cin >> s;
    
    dp[0] = 1;
    dp[1] = 1 - (int)(s[0] - '0');
    if (s[1] == '1'){
        dp[2] = 0;
    } else{
        dp[2] = Madd(dp[1], dp[0], MOD_VAL);
    }
    
    dpsum[0] = dp[0];
    dpsum[1] = dpsum[0] + dp[1];
    dpsum[2] = dpsum[1] + dp[2];
    
    //cout << dp[1] << " " << dp[2] << " " << dp[3] << endl;
    
    for(int i = 3; i <= n; i++){
        if (s[i - 1] == '1'){
            dp[i] = 0;
        }else if (i - k > 0){
            dp[i] = Msub(dpsum[i - 1], dpsum[i - k - 1], MOD_VAL);
        }else{
            dp[i] = Msub(dpsum[i - 1], 0, MOD_VAL);
        }
        //cout <<"i = "<< i << " dp " <<dp[i] << endl;
        dpsum[i] = Madd(dpsum[i - 1], dp[i], MOD_VAL);
        //cout << "i = " << i << "dp[i] = " << dp[i] << endl;
    }
    
    
    cout << dp[n] << endl;
    
    
    return 0;
}
