#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    setlocale(0, "");
   
    int n;
    int sum = 0;
    int mult = 1;

    cout << "Enter number ";
    cin >> n;

    for(int i=1;i<=n;i++){
        if(i % 2 == 0) sum += i;
        else mult *= i; 
    }

    cout << sum << " and " << mult;

    return 0;
}

//test