#include <iostream>
#include <vector>
using namespace std;

const long long INFTY = 2'000'000'000'000 + 2;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}

vector<vector <long long>> dp;
vector<vector <long long>> a;

long long f(int i, int j, int n, int m){
    if (i == 1 && j == 1 ){
        return a[1][1];
    } else if (i <= 0 || j <= 0 || i > n || j > m){
        return INFTY;
    }
    
    if (dp[i][j] != -1){
        return dp[i][j];
    } else{
        dp[i][j] = min(min(f(i - 1, j - 2, n, m), f(i - 2, j - 1, n, m)),
                       min(f(i + 1, j - 2, n, m), f(i - 2, j + 1, n, m))) + a[i][j];
        return dp[i][j];
    }
}

// перебор по диагонали
/*
for (int k = 1; k < n + m - 1; k++){
    for (int i = min(k, n - 1), j = max(k - n + 1, 0); i >= 0 && j < m; --i, ++j){
    }
}*/

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    dp.assign(n + 1, vector<long long> (m + 1, -1));
    a.resize(n + 1, vector<long long> (m + 1));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    long long answr =  f(n, m, n, m);
    //cout << answr << endl;
    if (answr >= INFTY/2){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
        vector<pair <int, int>> ans;
        int x = n, y = m;
        while (x > 0 && y > 0){
            ans.push_back({x, y});
            if (f(x - 1, y - 2, n, m) + a[x][y] == f(x, y, n, m)){
                x -= 1;
                y -= 2;
            } else if (f(x - 2, y - 1, n, m) + a[x][y] == f(x, y, n, m)){
                x -= 2;
                y -= 1;
            } else if (f(x + 1, y - 2, n, m) + a[x][y] == f(x, y, n, m)){
                x += 1;
                y -= 2;
            } else{
                x -= 2;
                y += 1;
            }
        }
        cout << answr << " " << ans.size() << endl;
        for (long long i = ans.size() - 1; i >= 0 ; i--){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    //ans.push_back({1, 1});
    
    
    
    return 0;
}
