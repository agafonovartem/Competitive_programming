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
    
    long long a, b;
    
    cin >> a >> b;
    
    long long g = gcd(a, b);
    cout << CNTR;
    
    return 0;
}
