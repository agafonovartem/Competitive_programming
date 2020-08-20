#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp.resize(n+1);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
