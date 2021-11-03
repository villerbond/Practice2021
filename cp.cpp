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
