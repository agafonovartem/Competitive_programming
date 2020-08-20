#include <iostream>
#include <vector>
using namespace std;
const long long infty = 1000000000;

vector<vector <long>> dp;
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
    
    dp.assign(n + 1, vector<long> (s + 1, -infty));
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j<= s; j++){
            if (w[i] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            //cout << "dp[" << i << "][" <<j << "] = " << dp[i][j] << endl;
        }
    }
    
    long ans = 0;
    int ans_idx = 0;
    for (int w = 0; w <= s; w++){
        if (ans < dp[n][w]){
            ans = dp[n][w];
            ans_idx = w;
        }
    }
    cout << ans << " ";
    //cout << ans_idx << endl;
    
    vector <int> answer;
    int i = n;
    int j = ans_idx;
    while (j >= 0 && i >0){
        if (w[i] <= j && dp[i][j] == dp[i-1][j - w[i]] + c[i]){
            
            answer.push_back(i);
            j -= w[i];
        }
        i--;
    }
    
    cout << answer.size() << endl;
    for (long i = answer.size() - 1; i >= 0; i--){
        cout << answer[i] << " ";
    }
    
    
    
    return 0;
}
