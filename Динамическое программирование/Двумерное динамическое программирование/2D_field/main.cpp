#include <iostream>
#include <vector>
using namespace std;






int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    
    vector<vector <int>> a(m + 1, vector<int> (n + 1));
    vector<vector <int>> dp(m + 1, vector<int> (n + 1));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[j][i];
            //cout << a[j][i] << " ";
        }
    }
    
    
    /*
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }*/
    
    //база
    dp[1][1] = 0;
    for (int i = 2; i <= m; i++){
        dp[i][1] = dp[i - 1][1] + abs(a[i][1] - a[i-1][1]);
        //cout << dp[i][1] << " ";
    }
    //cout << endl;
    for (int j = 2; j <= n; j++){
        dp[1][j] = dp[1][j - 1] + abs(a[1][j] - a[1][j-1]);
        //cout << dp[1][j] << " ";
    }
    
    //cout << endl;
    
    for (int i = 2; i <= m; i++){
        for (int j = 2; j <= n; j++){
            dp[i][j] = min(dp[i-1][j] + abs(a[i][j] - a[i-1][j]),
                           dp[i][j-1] + abs(a[i][j] - a[i][j-1]));
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    
    cout << dp[m][n] << endl;
    
    
    
    
    
    
    return 0;
}
