#include <iostream>
#include <vector>
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
    
    
    long x = n;
    vector<long> ans;
    while(x > 0){
        ans.push_back(x);
        if (x % 3 == 0 && dp[x] - 1 == dp[x/3]){
            x = x/3;
        } else if (x % 2 == 0 && dp[x] - 1 == dp[x/2]){
            x = x/2;
        } else {
            x = x - 1;
        }
    }
    
   
    
    cout << dp[n] << endl;
    for (long i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    return 0;
}
