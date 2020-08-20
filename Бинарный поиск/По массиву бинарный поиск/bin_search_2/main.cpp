#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int n = 0, m = 0;
    cin >> n >>m;
    int l = -1, r = n;
    int mid = 0;
    for (int i = 0; i < m; i++){
        mid = (r + l)/2;
        //cout << mid << endl;
        int a = 0;
        cin >> a;
        if (a == 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    
    cout << r;
    
    
    return 0;
}
