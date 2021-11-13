/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n,i=1;
    cout << "Input natural number: ";
    cin >> n;
    int max = n;
    
    while (n != 1) {
        i++;
        
        if (n%2 == 0) {
            n = n >> 1;
        } else {
            n = 3*n+1;
        }
        
        if (n > max) {
            max = n;
        }
        
    }
    
    cout << "Count of steps: " << i << endl;
    cout << "Max number: " << max << endl;
    return 0;
}
