#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<int> dist;
vector<set<int>> adj_list;
queue<int> q;


void bfs(int s){
    q.push(s);
    dist[s] = 0;
    
    while (q.empty() == false){
        int v = q.front();
        //cout << v << " ";
        q.pop();
        for (const auto&u : adj_list[v]){
            if (dist[u] == -1){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++){
        dist.assign(n + 1, -1);
        bfs(i);
        for (int i = 1; i <= n; i++){
            if (dist[i] != -1){
                sum += dist[i];
            }
        }
    }
    
    cout << sum / 2 << endl;
    
    
    return 0;
}
