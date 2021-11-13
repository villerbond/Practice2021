/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    
    int x;
    do {
        cout << "Input natural number: ";
        cin >> x;
    } while (x < 0);
    
    int N;
    do {
        cout << "Input number system: ";
        cin >> N;
    } while (N < 2 or N > 16);
    
    int tmp = x, m = 1;

    while (tmp) {
        m *= N;
        tmp /= N;
    }
    
    // m = m > 0 ? m-1 : 0;
    
    tmp = x;
    
    while (m) {
        int digit = tmp / m;
        if (digit < 10)
            cout << digit;
        else
            cout << char('A' + digit - 10);
        tmp %= m;
        m /= N;
    }
    
    return 0;
}
