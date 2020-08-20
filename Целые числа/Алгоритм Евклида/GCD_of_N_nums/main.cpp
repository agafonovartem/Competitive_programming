#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
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
    
    int n;
    
    cin >> n;
    long long a;
    cin >> a;
    for(int i = 0; i < n - 1; i++){
        long long b;
        cin >> b;
        a = gcd(a, b);
        if (a == 1){
            break;
        }
    }
    
    cout << a;
    
    return 0;
}
