#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            int v = (int)(s[j - 1] - '0');
            if (v == 1){
                adj_list[i].push_back(j);
            }
        }
    }
    
    for (int i = 1; i <= n ; i++){
        cout << adj_list[i].size() << " ";
        for (int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
