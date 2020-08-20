#include <iostream>
using namespace std;

long double  EPS = 1.e-12;

long double f(int a[5], long double x){
    long double res = 0;
    long double xs[5] = {1};
    for (int i = 1; i < 5; i++){
        xs[i] = xs[i-1] * x;
    }
    for (int i = 0; i < 5; i++){
        res+= a[i] * xs[i];
    }
    //cout << "F VALUE = " << res << endl;
    return res;
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int c_x = 0, c_y = 0, c_d = 0;
    
    cin >> c_x >> c_y >> c_d;
    int n = 0;
    cin >> n;
    
    int a[5] = {0};
    for (int i = n; i >= 0; i--){
        cin >> a[i];
    }
    
    long double x;
    cin >> x;
    
    //cout << f(a, x) << endl;
    
    
    
    long double r = c_x + c_d + 10;
    long double l = x;
    while(r - l > EPS){
        long double mid = (l+r)/2;
        //cout << " Mid = " << mid << endl;
        if ((f(a, mid) - c_y) * (f(a, mid) - c_y) + (mid - c_x) * (mid - c_x) - c_d*c_d < 0.0){
            //cout << "LEFT F = " << f(a, mid) << " LEFT = " << mid << endl;
            l = mid;
        }
        else{
            //cout << "RIGHT F = " << f(a, mid) << " RIGHT = " << mid  << endl;
            r = mid;
        }
    }
    cout.precision(16);
    cout <<(l+r)/2.0 << endl;
     
    
    
    return 0;
}
