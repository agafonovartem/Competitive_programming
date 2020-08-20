#include <iostream>
using namespace std;

long double  EPS = 1.e-9;

long double f(int a[6], long double x){
    long double res = 0;
    long double xs[6] = {1};
    for (int i = 1; i < 6; i++){
        xs[i] = xs[i-1] * x;
    }
    for (int i = 0; i < 6; i++){
        res+= a[i] * xs[i];
    }
    //cout << "F VALUE = " << res << endl;
    return res;
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    cin >> n;
    int a[6] = {0};
    for (int i = n; i >= 0; i--){
        cin >> a[i];
    }
    long double r ;
    long double l ;
    if (a[n] < 0){
        r = -10;
        l = 10;
    }
    else{
        r = 10;
        l = -10;
    }
    while(r - l > EPS){
        long double mid = (l+r)/2;
        //cout << " Mid = " << mid << endl;
        if (f(a, mid) < 0.0){
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
