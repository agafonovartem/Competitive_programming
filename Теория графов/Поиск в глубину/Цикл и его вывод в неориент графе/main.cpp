#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> used;
vector<set<int>> adj_list;
vector<int> cycle_list;
int from;
bool cycle = false;
int cycle_end = 0;

void dfs(int to, int from){
    used[to] = true;
    //cout << "current: " << to << endl;
    if (cycle == 0){
        cycle_list.push_back(to);
        //cout << to << " was pushed in answ " << endl;
    }
    for (const auto& u : adj_list[to]){
        //cout << "look at: " << u  << endl;
        if (used[u] == true && u != from && from != 0 && cycle == 0){
            //cout << "CYCLE ENDS: " << "u = " << u << " from = " << from << " current = " << to << endl;
            cycle_end = u;
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
            break;
        } else{
            dfs(i, 0);
        }
        //cout << "________" << endl;
    }
    if (cycle == false){
        cout << "NO";
    } else {
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
    }

    
    
    
    return 0;
}
