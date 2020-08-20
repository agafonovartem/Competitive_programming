#include <iostream>

using namespace std;
const long long mod = 1'000'000 + 7;

long long Mnorm(long long x, long long MOD){
    return  (x % MOD + MOD) % MOD;
}

long long Madd(long long a, long long b, long long MOD){
    return  Mnorm(Mnorm(a, MOD) + Mnorm(b, MOD), MOD);
}

long long Msub(long long a, long long b, long long MOD){
    return  Mnorm(Mnorm(a, MOD) - Mnorm(b, MOD), MOD);
}

long long Mmul(long long a, long long b, long long MOD){
    return  Mnorm(Mnorm(a, MOD) * Mnorm(b, MOD), MOD);
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b;
    cin >> a >> b;
    
    cout << Mmul(Msub(a, b, mod), Madd(a, b, mod), mod);
    
    return 0;
}
