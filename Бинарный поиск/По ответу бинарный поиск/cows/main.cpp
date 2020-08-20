#include <iostream>
using namespace std;

long long a[10005];

int Check(long long distance, int n){
    int cntr = 1;
    int ind = 0;
    for (int i = 1; i < n; i ++){
        if (a[i] - a[ind] >= distance){
            cntr++;
            ind = i;
            //cout << "ind = " << ind << endl;
        }
    }
    //cout << "COUNTER = " << cntr << endl;
    return cntr;
};

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
   
    
    long long l = 1;
    long long r = a[n-1];
    while(l + 1 < r){
        long long mid = (l + r)/2;
        //cout << "CHECK = " << Check(mid, n) << endl;
        if (Check(mid, n) < k){
            r = mid;
            //cout << "RIGHT = " << r << endl;
        }else{
            l = mid;
            //cout << "LEFT = " << l << endl;
        }
    }
    
    cout << l;
    return 0;
}
