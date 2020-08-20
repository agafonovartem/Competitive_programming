#include <iostream>

using namespace std;
int CNTR = 0;

long long gcd(long long a, long long b){
    if (a < b){
        return gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    
    CNTR ++;
    return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b, c;
    
    cin >> a >> b >> c;
    
    if (a < 0){
        a = - a;
    }
    if (b < 0){
        b = - b;
       }
    
    // ax + by = c have solution if c % gcd(a, b) = 0
    long long g = gcd(a, b);
    
    if (c % g == 0){
        cout << 1;
    }
    else{
        cout << 0;
    }
    
    return 0;
}
