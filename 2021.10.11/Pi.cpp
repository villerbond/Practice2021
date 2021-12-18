#include <iostream>

int main() {
    long double eps;
    int r;
    unsigned long long N = 0;
    long double S = 4.0;
    long double xn = S;
    
    do {
        std::cout << "Accuracy: ";
        std::cin >> eps;
        std::cout << "Radius: ";
        std::cin >> r;
    } while (eps <= 0 or r <= 0);
    
    // S (текущая) - S (предыдущая) = xn
    
    while (xn >= eps) {
        
        N++;
        xn = 4 / (2.0*N + 1.0);
        
        if (N % 2 == 0) {
            S += xn;
        } else {
            S -= xn;
        } 
    }
    
    std::cout << "Pi = " << S << std::endl;
    std::cout << "Count of steps = " << N << std::endl;
    
    unsigned long long x, y, hits = 0;
    
    for (unsigned long long i = 0; i < N; ++i) {
        
        x = rand() % (r+1);
        y = rand() % (r+1);
        
        if (x*x + y*y <= r*r) ++hits;
    }
    
    std::cout << "Pi = " << 4.0 * hits / N << std::endl;
    
    return 0;
}
