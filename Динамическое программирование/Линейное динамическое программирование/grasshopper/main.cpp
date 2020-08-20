#include <iostream>

using namespace std;
//int a[10001];


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    //long dp[n];
    
    
    // можно было бы еще сэкономить, сразу считывая а[i] в сумму 
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    long  p0 = 0;
    long  p1 = a[1];
    long  p2 = a[1]; // важно объявить так, а не нулем, чтобы проходил тест, когда всего 1 элт
    for (int i = 2; i <= n; i++){
        p2 = max(p0, p1) + a[i];
        p0 = p1;
        p1 = p2;
    }
    
    // вариант решения через массив
    /*
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
    }*/
    
    
    cout << p2;
    //cout << p2;
    
    
    return 0;
}
