#include <iostream>
#include <math.h>
using namespace std;
int Sieve[1000000+5];




int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int sum = 0;
    for (int n = 3; n <= N; n++){
        int p = 1;
        int add = 0;
        //cout << "n = " << n << endl;
        if (n > 2 && n % 2 == 0){
            //cout << "SUM + 2" << endl;
            add = 2;
            p = 0;
        }
        else{
            for (int i = 3; i*i <= n; i += 2){
                if (n % i == 0){
                    //cout << "SUM + " << i << endl;
                    add = i;
                    p = 0;
                    break;
                }
            }
        }
        if (p == 0){
            sum += add;
        }
    }
    
    cout << sum << endl;

    
    return 0;
}
