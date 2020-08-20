#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
int from;
bool cycle = false;

void dfs(int to, int from){
    used[to] = true;
    //cout << "current: " << to << endl;
    for (const auto& u : adj_list[to]){
        //cout << "look at: " << u  << endl;
        if (used[u] == true && u != from && from != 0){
            //cout << "CYCLE ENDS : " << "u = " << u << " from = " << from   << endl;
            cycle = true;
            return;
        } else if (used[u] == true){
            continue;
        }
        dfs(u, to);
        //cout << "current: "<< to  << endl;
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
    for (int i = 1; i <= n; i++){
        if (cycle == true){
            cout << "YES";
            break;
        } else{
            dfs(i, 0);
        }
        //cout << "________" << endl;
    }
    if (cycle == false){
        cout << "NO";
    }

    
    
    
    return 0;
}
