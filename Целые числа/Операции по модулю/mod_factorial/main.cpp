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
    
    if (N >= mod || N == 0){
        cout << 0;
    }
    else{
        for (long long i = N - 1; i > 0; i--){
            N = Mnorm(N, mod) * i;
        }
        cout << N;
    }
    
    
    return 0;
}
