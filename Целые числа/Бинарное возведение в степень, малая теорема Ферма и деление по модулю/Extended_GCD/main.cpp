//
//  main.cpp
//  Extended_GCD
//
//  Created by Артем on 14.05.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
using namespace std;
int extd_gcd(int r1, int r2, int &x1, int& y1, int& x2, int& y2, bool first = true){
    if (r1 < r2) {
        return extd_gcd(r2, r1, y1, x1, y2, x2, first);
    }
    if (first == true){
        x1 = 1;
        x2 = 0;
        y1 = 0;
        y2 = 1;
    }
    if (r2 == 0) {
        return r1;
    }
    int x = x1 - (r1/r2) * x2;
    int y = y1 - (r1/r2) * y2;
    x1 = x2;
    x2 = x;
    y1 = y2;
    y2 = y;
    return extd_gcd(r2, r1 % r2, x1, y1, x2, y2, false);
}


int main(int argc, const char * argv[]) {
    // решаем диафантово уравнение ax + by = c
    int a, b, c;
    cin >> a >> b >> c;
    
    int x = 0, y = 0, tX = 0, tY = 0;
    
    cout << "gcd = " << extd_gcd(a, b, x, y, tX, tY, true) << "; x = " << x << "; y = " << y << endl;
    
    // если с не делится на (a, b), то нет решений
    if (c % extd_gcd(a, b, x, y, tX, tY, true) != 0){
        cout << " NO SOLUTION " << endl;
    }
    // если с делится на (a, b)
    else{
        int x_answ = x * c / extd_gcd(a, b, x, y, tX, tY, true);
        int y_answ = y * c / extd_gcd(a, b, x, y, tX, tY, true);
        cout << x_answ << endl;
        cout << y_answ << endl;
    }
    
    return 0;
}
