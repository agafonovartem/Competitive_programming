#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> vert_list;
    
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = i; j <= n; j++){
            int v = (int)(s[j - 1] - '0');
            if (v == 1){
                vert_list.push_back({i, j});
            }
        }
    }
    
    cout << vert_list.size() << endl;
    for (const auto& item : vert_list){
        cout << item.first << " " << item.second << endl;
    }
    
    return 0;
}
