#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    setlocale(0, "");
   
    int n;
    int sum = 0;

    cout << "Enter n: ";
    cin >> n;
    

    for(int i=1;i<=n;i++){
        sum += 2*i-1;
    }
    cout << sum;

    return 0;
}