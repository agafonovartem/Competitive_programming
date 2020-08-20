#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long unsigned a, b, c;
    cin >> a >> b >> c;
    
    cout << (a*b*c)/(a*b + b*c + a*c) << endl;
    
    return 0;
}
