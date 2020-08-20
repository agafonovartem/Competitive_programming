#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;
const long long MOD_VAL = 1000000000+7;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}


/*
//ленивая динамика
int f(int i){
    if (i < 0){
        return 0;
    }
    if (i == 0){
        return 1;
    }
    if (dp[i] != -1){
        return dp[i];
    }
    if (a[i] == 1){ //клетка занята
        return 0;
    }else{ // клетка свободна
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[i];
    }
    
}*/

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
  
    dp.resize(n + 1);
    string s;
    cin >> s;
    
    dp[0] = 1;
    dp[1] = 1 - (int)(s[0] - '0');
    /*for (int i = 0; i < n; i++){
        cout << "i = " << i <<"s[i] = " << s[i] << endl;
    }*/
    if (s[1] == '1'){
        dp[2] = 0;
    } else{
        dp[2] = Madd(dp[1], dp[0], MOD_VAL);
    }
    
    
    
    
    
    
    for(int i = 3; i <= n; i++){
        if (s[i - 1] == '1'){
            dp[i] = 0;
        } else{
            dp[i] = Madd(
                         Madd(dp[i-1],
                              dp[i-2],
                              MOD_VAL),
                         dp[i-3],
                         MOD_VAL);
        }
        //cout << "i = " << i << "dp[i] = " << dp[i] << endl;
    }
    
    
    cout << dp[n] << endl;
    
    
    return 0;
}
