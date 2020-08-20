#include <iostream>

using namespace std;
const long long mod = 1'000'000 + 3;

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
    
    long long N;
    cin >> N;
    long long fib1 = 1, fib2 = 1, fib3 = 1;
    
    for (int i = 1 ; i < N; i++){
        fib3 = Mnorm(fib2 + fib1, mod);
        fib1 = fib2;
        fib2 = fib3;
    }
    
    cout << fib3;
    
    
    return 0;
}
