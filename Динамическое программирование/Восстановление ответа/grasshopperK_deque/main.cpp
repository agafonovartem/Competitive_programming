#include <iostream>
#include <vector>
#include <deque>


using namespace std;

vector<long long> dp;
vector<long long> a;
deque<pair<long long , long long>> q;

pair<long long , long long> deq_min(){
    return q.front();
}
void deq_add(pair<long long , long long> added_element){
    while (!q.empty() && q.back().first > added_element.first)
        q.pop_back();
    q.push_back (added_element);
}

void deq_pop(pair<long long , long long> removed_element){
    if (!q.empty() && q.front().first == removed_element.first)
    q.pop_front();
}




int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    
    dp.resize(n + 1);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector <long long> parent(n + 1);
    dp[0] = 0;
    deq_add({dp[0], 0});
    for(int i = 1; i <= n; i++){
        dp[i] = a[i] + deq_min().first;
        parent[i] = deq_min().second;
        //cout << "i =  " << i << " parent[i] = " << parent[i] << endl;
        deq_add({dp[i], i});
        if (i - k >= 0){
            deq_pop({dp[i - k], i - k});
        }
    }
    long long x = n;
    vector<long long> ans;
    while(x > 0){
        ans.push_back(x);
        x = parent[x];
    }
    cout << dp[n] << " " << ans.size() << endl;
    
    for (long long i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    
    
    return 0;
}
