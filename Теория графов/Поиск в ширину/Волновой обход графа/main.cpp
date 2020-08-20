#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
queue<int> q;
vector<int> answ;

void bfs(int s){
    q.push(s);
    used[s] = true;
    
    while (q.empty() == false){
        int v = q.front();
        cout << v << " ";
        q.pop();
        for (const auto&u : adj_list[v]){
            if (used[u]){
                continue;
            }
            used[u] = true;
            q.push(u);
        }
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
    bfs(v_start);
    
    
    return 0;
}
