#include <iostream>

using namespace std;

int main() {
    
    int N;
    cout << "Input natural N: ";
    cin >> N;
    
    int R;
    cout << "Input pozitive R: ";
    cin >> R;
    
    int n = 0;
    double x,y;
    int count1 = 0, count2 = 0;
    
    while (n != N) {
        x = rand() % R;
        y = rand() % R;
        
        if (x*x + y*y <= R*R) {
            count1++;
        } else {
            count2++;
        }
        n++;
    }
    
    cout << count1 / (count2+0.0);

    return 0;
}
