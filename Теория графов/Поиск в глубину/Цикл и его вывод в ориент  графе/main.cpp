#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> color;
vector<set<int>> adj_list;
vector<int> cycle_list;
int from;
bool cycle = false;
int cycle_end = 0;


void dfs(int v){
    color[v] = 1;
    if (cycle == 0){
        cycle_list.push_back(v);
        //cout << v << " was pushed in answ " << endl;
    }
    //cout << "current: " << v << endl;
    for (const auto& u : adj_list[v]){
        //cout << "look at: " << u << endl;
        if (color[u] == 1 && cycle == 0){
            cycle = true;
            //cout << "CYCLE FOUND at " << u << " current = " << v << endl;
            cycle_end = u;
            return;
        }
        if (color[u] == 0){
            dfs(u);
            //cout << "current " << u << endl;
        }
    }
    color[v] = 2;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    color.resize(n + 1);
    
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].insert(v);
    }
    
    for (int i = 1; i <= n; i++){
        if (cycle == true){
            break;
        } else{
            dfs(i);
        }
    }
    if (cycle == true){
        cout << "YES" << endl;
        int cycle_start_idx = 0;
        for (int i = 0; i < cycle_list.size(); i++){
            if (cycle_list[i] == cycle_end){
                cycle_start_idx = i;
                break;
            }
        }
        cout << cycle_list.size() - cycle_start_idx << endl;
        for (int i = cycle_start_idx; i < cycle_list.size(); i++){
            cout << cycle_list[i] << " ";
        }
    } else {
        cout << "NO";
    }
    

    
    
    
    return 0;
}
