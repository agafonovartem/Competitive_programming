#include <iostream>
#include <vector>
using namespace std;
const long long infty = 1000000000;

vector<vector <int>> dp;
vector<int> w;
vector<int> c;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    w.resize(n + 1);
    c.resize(n + 1);
    
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    
    dp.assign(n + 1, vector<int> (s + 1, -infty));
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j<= s; j++){
            if (w[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    int ans = 0;
    for (int w = 0; w <= s; w++){
        //cout << dp[n][w] << endl;
        ans = max(ans, dp[n][w]);
    }
    cout << ans << endl;
    
    
    
    return 0;
}
