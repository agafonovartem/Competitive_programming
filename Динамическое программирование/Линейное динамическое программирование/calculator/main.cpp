#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long dp[n+1];
    
    
  
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++){
        if (i % 2 == 0 && i % 3 == 0){
            dp[i] = min(min(dp[i / 3], dp[i / 2]), dp[i - 1]) + 1;
        }
        else if (i % 2 == 0 ){
            dp[i] = min( dp[i / 2], dp[i - 1]) + 1;
        }
        else if (i % 3 == 0 ){
            dp[i] = min( dp[i / 3], dp[i - 1]) + 1;
        }
        else{
            dp[i] = dp[i - 1] + 1;
        }
    }
   
    
    cout << dp[n] << endl;
    return 0;
}
