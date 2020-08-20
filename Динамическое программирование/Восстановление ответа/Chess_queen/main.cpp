#include <iostream>
#include <vector>
using namespace std;
const long long INFTY = 2'000'000'000'000 + 2;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<vector <long long>> dp(n + 1, vector<long long> (m + 1, INFTY));
    vector <long long> col_min_idx(m + 1, 0);
    vector <long long> row_min_idx(n + 1, 0);
    vector <long long> diag_min_idx(n + m, 0);
    vector<vector <long long>> a(n + 1, vector<long long> (m + 1));
    
    vector<vector <long long>> parent_x(n + 1, vector<long long> (m + 1, -1));
    vector<vector <long long>> parent_y(n + 1, vector<long long> (m + 1, -1));
    
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    for (int k = 1; k <= n + m - 1; k++){
        for (int i = min(k, n), j = max(1, k - n + 1); i >= 1 && j <= m; i--, j++){
            /*
            cout << "_________________" << endl;
            cout << " i = " << i << " j = " << j << endl;
            cout << " n+i-j = #diag = " << m+i-j << endl;
            cout << " row_min_idx: ";
            for (int i = 1; i <= n; i++){
                cout << row_min_idx[i] << " ";
            }
            
            cout << endl <<" col_min_idx: ";
            for (int i = 1; i <= m; i++){
                cout << col_min_idx[i] << " ";
            }
            cout << endl <<" diag_min_idx: ";
            for (int i = 1; i <= m + n - 1; i++){
                cout << diag_min_idx[i] << " ";
            }
            cout << endl;
            */
            
            
            
            
            if (i == 1 && j == 1){
                dp[i][j] = a[i][j];
                row_min_idx[1] = 1;
                col_min_idx[1] = 1;
                diag_min_idx[m] = 1;
            } else{
                long long diag_x, diag_y;
                if (i - j > 0){//выше диагонали
                    diag_y = diag_min_idx[m+i-j];
                    diag_x = i-j + diag_y;
                }
                else{
                    diag_x = diag_min_idx[m+i-j];
                    diag_y = diag_x - i + j;
                }
                
                //cout << " diag_x = " << diag_x << " diag_y = " << diag_y << endl;
                dp[i][j] = a[i][j] + min(min(dp[i][row_min_idx[i]], dp[col_min_idx[j]][j]),
                                         dp[diag_x][diag_y]);
                //cout << " dp[i][j] = " << dp[i][j] << endl;
                if (dp[i][j] == a[i][j] + dp[col_min_idx[j]][j]){
                    parent_x[i][j] = col_min_idx[j];
                    parent_y[i][j] = j;
                } else if (dp[i][j] == a[i][j] + dp[i][row_min_idx[i]]){
                    parent_x[i][j] = i;
                    parent_y[i][j] = row_min_idx[i];
                } else{
                    parent_x[i][j] = diag_x;
                    parent_y[i][j] = diag_y;
                }
                if (dp[col_min_idx[j]][j] > dp[i][j]){
                    col_min_idx[j] = i;
                }
                if (dp[i][row_min_idx[i]] > dp[i][j]){
                    row_min_idx[i] = j;
                }
                //cout << " dp[diag_x][diag_y] = " << dp[diag_x][diag_y] << endl;
                if (dp[diag_x][diag_y] > dp[i][j]){
                    if (i - j > 0){
                        diag_min_idx[m+i-j] = j;
                    } else{
                        diag_min_idx[m+i-j] = i;
                    }
                }
                
            }
        }
    }
    
    
    vector<pair<long long, long long>> ans;
    long long x = n;
    long long y = m;
    while(x > 0 && y > 0){
        ans.push_back({x, y});
        long long old_x = x, old_y = y;
        x = parent_x[old_x][old_y];
        y = parent_y[old_x][old_y];
    }
    
    cout << dp[n][m] << " " << ans.size() << endl;
    
    for(long i = ans.size() - 1; i >= 0 ; i--){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    
    return 0;
}


