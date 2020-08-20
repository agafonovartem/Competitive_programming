#include <iostream>
using namespace std;
long int MAXVAL = 1'000'000'000;
long int a[200000];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0, m = 0;
    cin >> n >>m;
    for (int i = 0; i < n; i++){
        long int b = 0;
        cin >> b;
        a[i] = b;
    }
    
    
    for (int i = 0; i < m; i++){
        long int c = 0;
        cin >> c;
        int l = -1, r = n;
        
        while(l+1 < r){
            int mid = (l+r)/2;
            if (a[mid] < c){
                l = mid;
                //cout << "upd left = " << l << endl;
            }
            else{
                r = mid;
                //cout << "upd right = " << r << endl;
            }
        }
        
        if(a[r] == c){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
