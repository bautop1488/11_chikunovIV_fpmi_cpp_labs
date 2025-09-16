#include<iostream>
#include<cmath>


bool isPrime(int x){
    int o = 0;
    for(int i=1;i<=x;i++){
        if(x%i == 0){
            o++;
        }
    }
    if(o == 2){
        return true;
    }
    return false;
}

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    int n, max_power;

    cout << "Type n: ";
    cin >> n;

    if(!cin >> n){
        cout << "Incorrect input, error";
        std::exit(1);
    }

    for(int i=1;i<=n;i++){
        if(n <= pow(2, i)){
            max_power = i;
            break;
        }
    }

    cout << "All k's: ";
    for(int p=1;p<=max_power;p++){
        if(isPrime(p) && pow(2, p)-1 <= n){
            cout << pow(2, p) - 1 << " ";
        }
    }

    return 0;
}
