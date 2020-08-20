#include <iostream>

using namespace std;

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


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    cout <<  fastpow(N, N, M);
    
    return 0;
}
