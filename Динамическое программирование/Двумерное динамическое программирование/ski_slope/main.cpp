#include <iostream>
#include <vector>
using namespace std;






int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<vector <int>> a(n + 1, vector<int> (n + 1));
    vector<vector <int>> dp(n + 1, vector<int> (n + 1));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> a[j][i];
        }
    }
    /*
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }*/
    
    
    
    
    //cout << "BASE: " << endl;
    //база
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++){
        dp[1][i] = dp[1][i - 1] + a[1][i];
        dp[i][i] = dp[i-1][i-1] + a[i][i];
        //cout << dp[1][i] << " " << dp[i][i] << endl;
    }
    //cout << endl;
    
    
    for (int j = 3; j <= n; j++){
        for (int i = 2; i <= j - 1; i++){
            dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]) + a[i][j];
            //cout << "i = " << i << " j = " << j << " dp = "<< dp[i][j] << endl;
        }
    }
    
    int max = dp[1][n];
    for (int i = 2; i <= n; i++){
        if (dp[i][n] >= max){
            max = dp[i][n];
        }
    }
    cout << max << endl;
    
    
    
    
    return 0;
}
