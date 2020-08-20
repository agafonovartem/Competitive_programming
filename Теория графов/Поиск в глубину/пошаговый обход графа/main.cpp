#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
vector<int> answer;

void dfs(int v){
    used[v] = true;
    answer.push_back(v);
    for (const auto& u : adj_list[v]){
        if (used[u] == true){
            continue;
        }
        dfs(u);
        answer.push_back(v);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    used.resize(n + 1);
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    int v_start;
    cin >> v_start;
    
    dfs(v_start);
    cout << answer.size() << endl;
    for (const auto& u : answer){
        cout << u << " ";
    }
    
    
    
    
    
    return 0;
}
