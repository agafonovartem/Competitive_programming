#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj_list(n + 1);
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    
    
    for (int i = 1; i <= n ; i++){
        cout << adj_list[i].size() << " ";
        for (const auto& item: adj_list[i]){
            cout << item << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
