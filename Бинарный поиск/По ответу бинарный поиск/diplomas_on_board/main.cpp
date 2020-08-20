#include <iostream>
#include <math.h>
using namespace std;


long long nDiplomas(long long len, long long w, long long h){
    return (len / w) * (len / h);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long int w, h, n;
    cin >> w >> h >> n;
    
    long long l = min(w,h);
    long long r = max(w, h) * n;
    
    while(l+1 < r){
        long long mid = (l + r) / 2;
        //cout << " l = " << l << " r = " << r << endl;
        //cout << mid << endl;
        if (nDiplomas(mid, w, h) < n){
            l = mid;
            cout << "LEFT = " << l << endl;
        }
        else{
            r = mid;
            cout << "RIGHT = " << r << endl;
        }
    }
    
    cout << r << endl;
    
    
    return 0;
}
