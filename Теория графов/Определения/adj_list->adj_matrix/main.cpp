#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj_matrix(n + 1, vector<int> (n + 1, 0));
    
    for (int i = 1; i <= n; i++){
        int size;
        cin >> size;
        for (int j = 0; j < size; j++){
            int u;
            cin >> u;
            if (u < i){
                adj_matrix[i][u] = 1;
                adj_matrix[u][i] = 1;
            }
        }
    }
    
    
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cout << adj_matrix[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}
