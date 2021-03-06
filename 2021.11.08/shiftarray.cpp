#include <iostream>

void reverseArray(int A, int begin, int end);
void shiftArray(int A[], int n, int k);

int main() {

    int A[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int sh;
    std::cout << "Input shift: ";
    std::cin >> sh;
    
    shiftArray(A, 10, sh);
    
    for (int i = 0; i < 10; ++i) {
        std::cout << A[i] << " ";
    }
    
    return 0;
}

void reverseArray(int* A, int begin, int end) {
    int n = 0;
    for (int i = begin - 1; i < begin - 1 + (end - begin + 1) / 2; ++i) {
        std::swap(A[i], A[end - 1 - n]);
        ++n;
    }
}

void shiftArray(int A[], int n, int k) {
    
    if (n != 0) {
        
        while (k < 0) {
            k += n;
        }
    
        k = k % n;
    
        reverseArray(A, 1, k);
        reverseArray(A, k+1, n);
        reverseArray(A, 1, n);
        
        }
}
