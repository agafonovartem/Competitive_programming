#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int n = 0, m = 0;
    cin >> n >>m;
    for (int i = 0; i < m; i++){
        int k = 0;
        cin >> k;
        int l = -1, r = n;
        int steps = 0;
        while (l + 1 < r) {
            int mid = (l + r)/2;
            if (mid < k){
                l = mid;
            }
            else{
                r = mid;
            }
            steps ++;
        }
        cout << steps << endl;
        
    }
    
    
    return 0;
}
