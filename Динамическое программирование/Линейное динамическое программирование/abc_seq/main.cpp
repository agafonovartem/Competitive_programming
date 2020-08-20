#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp;

/*
 Найдите, сколько существует строк заданной длины n, состоящих только из символов
 a, b и c, и не содержащих подстроки ab.
 
 Идея решения: f(n) = 2f(n-1) (посл начинается с b или c) +
 + f(n-2) (посл начинается с a =>  за ней идет c) + f(n-3) (наинается с aac) +...+ f(0) + 1
 
 Расписа для n-1 и вычев получим рекурренту: f(n) = 3f(n-1) - f(n-2)
 */


long long f(int i){
   
    if (i == 0){
        return 1;
    }
    if (i == 1){
        return 3;
    }
    if (dp[i] != -1){
        return dp[i];
    } else{
        dp[i] = 3 * f(i - 1) - f(i - 2);
        return  dp[i];
    }
};


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    
    cout << f(n) << endl;
    
    
    return 0;
}
