#include <iostream>
#include <math.h>
using namespace std;
unsigned long long onethird = 6148914691236517205;
// вместо этого надо было юзать UINT64_MAX и писать UINT64_MAX/3 (это и есть одна треть)

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long m;
    cin >> m;
    
    
    if (m % 3 == 0){
        //cout << "mod is 0" << endl;
        cout << m/3;
    }
    else if (m % 3 == 2){
        //cout << "mod is 2" << endl;
        cout << onethird * 1 + m/3 + 1;
    }
    else if (m % 3 == 1){
        //cout << "mod is 1" << endl;
        cout << onethird * 2 + m/3 + 1;
    }

    
    
    return 0;
}

