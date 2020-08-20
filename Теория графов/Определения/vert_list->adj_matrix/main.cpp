#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_matrix(n + 1, vector<int> (n + 1, 0));
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    
    
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cout << adj_matrix[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}
