#include <iostream>
#include <cmath>

using namespace std;

int main () {
    
    int N = 1;
    int n = 0;
    long double S0=0, eps;
    long double x=4;
    long double S1 = 4.0;
    
    do {
        cout << "Accuracy: ";
        cin >> eps;
    } while (eps <= 0);
    
    while (abs(S1 - S0) >= eps) {
        
        x = - x * ((2*n+1.0)/(2*n+3.0));
        S0 = S1;
        S1 += x;
        n++;
        N++;
    }
    
    cout << N;
    
    return 0;
}