//
//  main.cpp
//  Max_idx
//
//  Created by Артем on 24.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <stdint.h>

const int MAXN = 100050;
const int MAXVALUE = 1000000500;
int a[MAXN];
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int maxa = -MAXVALUE - 1;
    int maxpos = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > maxa){
            maxa = a[i];
            maxpos = i + 1;
        }
    }
    
    cout << maxpos;
    
    return 0;
}
