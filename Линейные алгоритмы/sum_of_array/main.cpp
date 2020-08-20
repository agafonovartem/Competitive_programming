//
//  main.cpp
//  sum_of_array
//
//  Created by Артем on 24.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <stdint.h>

const int MAXN = 100050;
int a[MAXN];
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long int sum = 0;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    cout << sum;
    
    return 0;
}
