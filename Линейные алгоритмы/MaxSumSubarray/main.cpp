#include <iostream>


using namespace std;

const int MAXN = 300000;
const long int MAXVAL = 1000000005;
long int arr[MAXN];






int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long int a;
    
    for (int i = 0 ; i < n; i++){
        cin >> a;
        arr[i] = a;
    }
    
    long int max_sub_sum = - MAXVAL -1;
    int sub_low = 0, sub_high = 0;
    long int max_right_sub_sum = 0;
    int right_sub_low = 0;
    for (int i = 0; i < n; i++){
        max_right_sub_sum += arr[i];
        if (max_right_sub_sum > max_sub_sum){
            max_sub_sum = max_right_sub_sum;
            sub_high = i;
            sub_low = right_sub_low;
        }
        if (max_right_sub_sum < 0){
            max_right_sub_sum = 0;
            right_sub_low = i + 1;
        }
    }
    
    cout << max_sub_sum;
    
    return 0;
}
