#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    long dp[n+1];
    
    
    //cout << "INPUT ARRAY: " ;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        //cout << a[i] << " ";
    }
    //cout << endl;
    
    //cout << "a_n = "  << a[5] << endl;
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++){
        //cout << "MAXIMUM  = " << max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) << endl;
        //cout << "i = " << i << " a_i = " << a[i] << endl;
        if (i == 2){
            dp[i] = dp[i - 1] + a[i];
        }
        else if (i == 3 || i == 4){
            dp[i] = max(dp[i - 1], dp[i - 3]) + a[i];
        }
        else {
            dp[i] = max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) + a[i];
        }
        //cout << dp[i] << endl;
    }
    
    long x = n;
    vector<long> ans;
    while(x > 0){
        ans.push_back(x);
        if (dp[x - 1] == dp[x] - a[x]){
            x--;
        } else if (dp[x - 3] == dp[x] - a[x]){
            x -= 3;
        } else{
            x -= 5;
        }
    }
    
    
    
    cout << dp[n] << " " << ans.size() << endl;
    for(long i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    
    
    return 0;
}
