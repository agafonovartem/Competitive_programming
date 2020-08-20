#include <iostream>
using namespace std;

long long a[10005];

bool Check(long long max_len, int n, int k){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i]/max_len;
    }
    //cout << "SUM = " << sum << endl;
    if (sum >= k){
        return true;
    }
    else{
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    long long max = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max){
            max = a[i];
        }
    }
    
    //cout << "MAX = " << max << endl;
    
   
    
    long long l = 0;
    long long r = max + 1;
    while(l + 1 < r){
        long long mid = (l + r)/2;
        //cout << "CHECK = " << Check(mid, n) << endl;
        if (Check(mid, n, k)){
            l = mid;
            //cout << "LEFT = " << l << endl;
        }else{
            r = mid;
            //cout << "RIGHT = " << r << endl;
        }
    }
    cout << l;
    return 0;
}
