#include <iostream>

unsigned long long MAX_VAL = 1'000'000'000'000'000'000;

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if (a < b){
        return gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long a, b;
    cin >> a >> b;
    
    unsigned long long g = gcd (a, b);
    //lcm = |a * b|/gcd(a, b)
    if (a / g >= MAX_VAL / b + 1){
        cout << -1;
    }
    else{
        cout << a * (b/g);
    }
    
    return 0;
}
