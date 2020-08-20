#include <iostream>

using namespace std;
const long long mod = 1'000'000'000 + 7;

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

long long fastpow(long long a, long long n, long long MOD){
    if (n == 0LL){
        return 1LL;
    }
    if (n % 2 == 1){
        return a * fastpow(a, n - 1, MOD) % MOD;
    }
    long long tmp = fastpow(a, n/2, MOD) % MOD;
    return (tmp * tmp) % MOD;
}

long long Mdiv(long long a, long long b, long long MOD){
    return  Mmul (a, fastpow(b, MOD - 2LL, MOD), MOD);
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << Madd(Mdiv(a, b, mod), Mdiv(c, d, mod), mod);
    
    return 0;
}
