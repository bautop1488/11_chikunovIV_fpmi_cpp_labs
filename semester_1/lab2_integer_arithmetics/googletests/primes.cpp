#include <vector>
#include <cmath>
#include <stdexcept>

std::vector<int> FindPrimesInRange(int a, int b) {
    std::vector<int> primes;
    
    if (a > b) {
        throw std::out_of_range("Wrong interval!");  
    }
    
    for (int i = std::max(2, a); i <= b; ++i) {
        
        bool isPrime = true;
        
        for (int k = 2; k * k <= i; ++k) {
            if (i % k == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            primes.push_back(i);
        }
    }
    
    return primes;
}