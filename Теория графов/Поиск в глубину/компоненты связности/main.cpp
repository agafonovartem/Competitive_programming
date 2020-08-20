#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
int cntr = 0;

void dfs(int v){
    used[v] = cntr;
    for (const auto& u : adj_list[v]){
        if (used[u] == cntr){
            continue;
        }
        dfs(u);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    used.resize(n + 1, 0);
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    for (int i = 1; i <= n; i++){
        if (used[i] == 0){
            cntr++;
            dfs(i);
        }
    }
    cout << cntr << endl;
    for (int i = 1; i <= n; i++){
        cout << used[i] << " ";
    }
    
    
    
    
    
    
    return 0;
}

