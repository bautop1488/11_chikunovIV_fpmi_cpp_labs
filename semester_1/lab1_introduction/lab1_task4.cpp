#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    setlocale(0, "");
   
    int k;
    int sum = 1;

    cout << "Enter k: ";
    cin >> k;
    
    
    for(int i=k%2+2;i<=k;i+=2){
        sum *= i;
    }
    
    cout << sum;

    return 0;
}