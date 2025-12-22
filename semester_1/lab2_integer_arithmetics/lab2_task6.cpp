#include <iostream>
#include <cmath>

bool is_prime(int x){
    int dividers = 0;
    for(int i=2; i <= sqrt(x)+1;i++){
        if(x % i == 0){
            dividers++;
        }
    }
    return dividers==0;
}

int main(){
    int n;

    std::cout << "type n: ";

    if(!(std::cin >> n)){
        std::cout << "Invalid input, error";
        std::exit(1);
    }

    std::cout << "all k's: " << std::endl;

    int l = log2(n);
    //std::cout << l << ' ';
    for(int i=1;i <= l;i++){
        if(is_prime(i)){
            std::cout << pow(2, i)-1 << std::endl;
        }
    }

    return 0;
}