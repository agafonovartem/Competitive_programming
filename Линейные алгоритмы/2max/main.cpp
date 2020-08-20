//
//  main.cpp
//  2max
//
//  Created by Артем on 24.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>

const int MAXN = 10000500;
const long int MAXVALUE = 1791791792;
long int arr[MAXN];
using namespace std;
long int cur;

long int NextRand(long int a , long int b) {
    long int mod = 1791791791;
    cur = (cur * a + b) % mod;
    return cur;
}



int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    size_t n;
    cin >> n;
    long int a, b;
    cin >> cur >> a >> b;
    
    int max_pos1 = 0;
    int max_pos2 = 0;
    
    for (size_t i = 0; i < n; i++){
        arr[i] = NextRand(a, b);
    }
    
    
    long int max1 = -MAXVALUE-1;
    long int max2 = -MAXVALUE-1;
    
    for (int i = 0; i < n; i++){
        if (max1 < arr[i] ){
            max1 = arr[i];
            max_pos1 = i;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (i != max_pos1){
            if (max2 < arr[i] ){
                max2 = arr[i];
                max_pos2 = i;
            }
        }
    }
    
    cout << max_pos1+1 << " " << max_pos2 + 1;
    
    
    
    return 0;
}

