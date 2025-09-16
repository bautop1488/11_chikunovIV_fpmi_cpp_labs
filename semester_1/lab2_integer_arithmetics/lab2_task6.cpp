#include <iostream>
#include <cmath>

bool is_prime(int x){
    int d = 0;
    for(int i=1; i <= x;i++){
        if(x % i == 0){
            d++;
        }
    }
    if(d==2){
        return true;
    }
    else{
        return false;
    }
}

int main(){


    int n;
    std::cout << "type n: ";
    std::cin >> n;

    if(!std::cin >> n){
        std::cout << "Invalid input, error";
        std::exit(1);
    }

    std::cout << "all k's: " << std::endl;

    for(int i=1;pow(2, i)-1 <= n;i++){
        if(is_prime(i)){
            std::cout << pow(2, i)-1 << std::endl;
        }
    }

    return 0;
}