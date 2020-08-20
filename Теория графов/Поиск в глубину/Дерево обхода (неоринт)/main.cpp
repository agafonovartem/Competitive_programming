#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
vector<set<int>> vert_list;
vector<int> answ;

void dfs(int v){
    used[v] = true;
    for (const auto& u : adj_list[v]){
        if (used[u] == true){
            continue;
        }
        set <int> cur_vertex = {};
        cur_vertex.insert(v);
        cur_vertex.insert(u);
        for (const auto& item : cur_vertex){
            cout << item << " " ;
        }
        cout << endl;
        for (int i = 1; i <= vert_list.size() - 1; i++){
            if (vert_list[i] == cur_vertex){
                answ.push_back(i);
                break;
            }
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
    used.resize(n + 1);
    vert_list.resize(m + 1);
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        vert_list[i].insert(v);
        vert_list[i].insert(u);
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    
    
    dfs(1);
    cout << answ.size() << endl;
    for (const auto& item : answ){
        cout << item << " ";
    }
    
    
    return 0;
}
