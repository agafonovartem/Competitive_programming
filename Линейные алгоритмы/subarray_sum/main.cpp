#include <iostream>


using namespace std;

const int MAXN = 300000;
long int arr[MAXN];






int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    long int a;
    arr[0] = 0;
    for (int i = 1 ; i < n + 1; i++){
        cin >> a;
        arr[i] = arr[i-1] + a;
    }
    int l = 0, r = 0;
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        cout << arr[r] - arr[l-1] << endl;
    }
    return 0;
}
