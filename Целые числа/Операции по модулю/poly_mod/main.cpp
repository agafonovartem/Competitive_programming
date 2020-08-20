#include <iostream>
#include <math.h>

using namespace std;
long long a[1001];

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
    
    int n, M;
    cin >> n >> M;
    
    //cout << " n = " << n << " m = " << M << endl;
    for (int i = n; i >= 0; i--){
        //cout << "i = " << i << endl;
        cin >> a[i];
    }
    
    long long answ = -1;
    for (long long x = 0; x < M; x++){
        //cout << "x = " << x << endl;
        long long total = Mnorm(a[0] , M);;
        long long r = Mnorm(x, M);
        for (int i = 1; i <= n; i++){
            //cout << "i = " << i << endl;
            //cout << "total % M = " << Mnorm(total, M) << endl;
            //cout << "r**i * a[i] = " << r * a[i] << endl;
            //cout << "r**i * a[i] % M = " << Mnorm(r * a[i], M) << endl;
            total = Madd(total, Mmul(r, a[i], M) , M);
            //cout << "total = " << total << endl;
            r = Mmul(r, x, M);
        }
        //cout << "x = " << x <<" total = " << total << endl;
        if (Mnorm(total, M) == 0){
            answ = x;
            break;
        }
    }
    cout << answ;
    return 0;
}

