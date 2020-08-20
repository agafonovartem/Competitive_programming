#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long N, p = 1;
    cin >> N;
    
    
    if (N > 2 && N % 2 == 0){
        p = 0;
    }
    else{
        for (int i = 3; i * i <= N; i += 2){
            if (N % i == 0){
                p = 0;
                break;
            }
        }
    }
    
    cout << p;
    
    
    
    
    return 0;
}
