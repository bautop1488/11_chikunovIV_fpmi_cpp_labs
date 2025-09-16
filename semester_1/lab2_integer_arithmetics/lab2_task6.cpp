#include<iostream>
#include<cmath>


bool is_prime(int x){
    int amount_of_dividers = 0;
    for(int i=1;i<=x;i++){
        if(x%i == 0){
            amount_of_dividers++;
        }
    }
    if(amount_of_dividers == 2){
        return true;
    }
    return false;
}

int main(){
    int n, max_power;

    std::cout << "Type n: ";
    std::cin >> n;

    if(!std::cin >> n){
        std::cout << "Incorrect input, error";
        std::exit(1);
    }

    for(int i=1;i<=n;i++){
        if(n <= pow(2, i)){
            max_power = i;
            break;
        }
    }

    std::cout << "All k's: ";
    for(int p=1;p<=max_power;p++){
        if(is_prime(p) && pow(2, p)-1 <= n){
            std::cout << pow(2, p) - 1 << " ";
        }
    }

    return 0;
}
