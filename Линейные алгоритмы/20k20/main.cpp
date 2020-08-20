#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool quit = false;
    if (n < 98765432){
        for (int i = n + 1; i < 98765432; i++){
            int k = 0;
            quit = true;
            n = i;
            long int cntr[10] ={};
            
            while(n != 0){
                int digit = n % 10;
                cntr[digit] ++;
                n = n / 10;
                k+= 1;
                
                
                if (cntr[digit] > 1){
                    //cout << "MORE THAN 2 SAME ELEMENTS";
                    quit = false;
                    break;
                }
                else if (digit == 0 && cntr[digit] > 0){
                    //cout << "CONSIST 0";
                    quit = false;
                    break;
                }
                else if (digit == 2 && cntr[digit] > 0){
                    //cout << "CONSIST 2";
                    quit = false;
                    break;
                }
            }
            
            if (quit){
                cout << i;
                break;
            }
        }
    }
    
    if (quit == false){
        cout << -1;
    }
    
    return 0;
}
