#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

vector<vector<int>> dist;
queue<pair<int, int>> qu;
int p, q;
int x1, y1, x2, y2;
int m, n;


int bfs(int i, int j){
    qu.push({i, j});
    dist[i][j] = 0;
    while (qu.empty() == false){
        pair<int, int> v = qu.front();
        qu.pop();
        //cout << "POPED FROM STACK: " << v.first << " " << v.second << endl;
        if (v.first == x2 && v.second == y2){
            return dist[v.first][v.second];
        }
        if (v.first + p <= m && v.second + q <= n){
            if (dist[v.first + p][v.second + q] == -1 ){
                dist[v.first + p][v.second + q] = dist[v.first][v.second] + 1;
                qu.push({v.first + p, v.second + q});
                //cout << "ADDED TO STACK:" << v.first + p << " " << v.second + q << endl;
            }
        }
        if (v.first - p > 0 && v.second + q <= n){
            if (dist[v.first - p][v.second + q] == -1 ){
                dist[v.first - p][v.second + q] = dist[v.first][v.second] + 1;
                qu.push({v.first - p, v.second + q});
                //cout << "ADDED TO STACK:" << v.first - p << " " << v.second + q << endl;
            }
        }
        if (v.first + p <= m && v.second - q > 0){
            if (dist[v.first + p][v.second - q] == -1 ){
                dist[v.first + p][v.second - q] = dist[v.first][v.second] + 1;
                qu.push({v.first + p, v.second - q});
                //cout << "ADDED TO STACK:" << v.first + p << " " << v.second - q << endl;
            }
        }
        if (v.first - p > 0  && v.second - q > 0){
            if (dist[v.first - p][v.second - q] == -1 ){
                dist[v.first - p][v.second - q] = dist[v.first][v.second] + 1;
                qu.push({v.first - p, v.second - q});
                //cout << "ADDED TO STACK:" << v.first - p << " " << v.second - q << endl;
            }
        }
        if (v.first + q <= m && v.second + p <= n){
            if (dist[v.first + q][v.second + p] == -1 ){
                dist[v.first + q][v.second + p] = dist[v.first][v.second] + 1;
                qu.push({v.first + q, v.second + p});
                //cout << "ADDED TO STACK:" << v.first + q << " " << v.second + p << endl;
            }
        }
        if (v.first - q > 0 && v.second + p <= n){
            if (dist[v.first - q][v.second + p] == -1 ){
                dist[v.first - q][v.second + p] = dist[v.first][v.second] + 1;
                qu.push({v.first - q, v.second + p});
                //cout << "ADDED TO STACK:" << v.first - q << " " << v.second + p << endl;
            }
        }
        if (v.first + q <= m && v.second - p > 0){
            if (dist[v.first + q][v.second - p] == -1 ){
                dist[v.first + q][v.second - p] = dist[v.first][v.second] + 1;
                qu.push({v.first + q, v.second - p});
                //cout << "ADDED TO STACK:" << v.first + q << " " << v.second - p << endl;
            }
        }
        if (v.first - q > 0 && v.second - p > 0){
            if (dist[v.first - q][v.second - p] == -1 ){
                dist[v.first - q][v.second - p] = dist[v.first][v.second] + 1;
                qu.push({v.first - q, v.second - p});
                //cout << "ADDED TO STACK:" << v.first - q << " " << v.second - p << endl;
            }
        }
        
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    cin >> p >> q;
    cin >> x1 >> y1 >> x2 >> y2;
    dist.assign(m + 1, vector<int>(n + 1, -1));
    
    cout << bfs(x1, y1);
    
    
    return 0;
}
