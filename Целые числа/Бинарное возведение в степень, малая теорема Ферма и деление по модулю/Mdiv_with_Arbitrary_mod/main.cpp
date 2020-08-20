#include <iostream>
using namespace std;

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

long long extd_gcd(long long r1, long long r2, long long &x1, long long& y1, long long& x2, long long& y2, bool first = true){
    if (r1 < r2) {
        return extd_gcd(r2, r1, y1, x1, y2, x2, true);
    }
    if (first == true){
        x1 = 1;
        x2 = 0;
        y1 = 0;
        y2 = 1;
    }
    if (r2 == 0) {
        return r1;
    }
    long long x = x1 - (r1/r2) * x2;
    long long y = y1 - (r1/r2) * y2;
    x1 = x2;
    x2 = x;
    y1 = y2;
    y2 = y;
    return extd_gcd(r2, r1 % r2, x1, y1, x2, y2, false);
}

// деление по простому модулю
long long Mdiv2(long long a, long long b, long long MOD){
    long long x1, x2, y1, y2;
    long long d = extd_gcd(b, MOD, x1, y1, x2, y2, true);
    if (a % d != 0) {
        return -1LL;
    }
    return Mmul((a/d), x1, MOD);
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, n, m;
    cin >> a >> n >> m;
    long long sum = 0;
    long long cur = 1;
    for (int i = 1; i <= n; i ++){
        cur = Mdiv2(cur, a, m);
        //cout << "CURRENT = " <<cur << endl;
        if (cur == -1){
            sum = -1;
            break;
        }
        sum =  Madd(sum, Mmul(cur, i, m), m);
    }
    
    cout << sum;
    
    return 0;
}
