#include <iostream>
using namespace std;


long long nDiplomas(long long len, long long w, long long h){
    return (len / w) * (len / h);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long N;
    int x, y;
    cin >> N >> x >> y;
    long long l = 0;
    long long r = max(x, y) * N;
    
    int tmp = min(x, y);
    y = max(x, y);
    x = tmp;
    
    
    
    while (l + 1 < r) {
        long long mid = (l+r)/2;
        // тратим х на создание 1ой копии
        if (mid/x + (mid - x)/y < N){
            l = mid;
            //cout << "LEFT = " << l << endl;
        }
        else{
            r = mid;
            //cout << "RIGHT = " << r << endl;
        }
    }
    
    cout << r;
    
    
    
    return 0;
}
