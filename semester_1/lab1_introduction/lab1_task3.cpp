#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;

int main(){
    setlocale(0, "");
   
    int n;
    int sum = 0;

    cout << "Enter n: ";
    cin >> n;
    

    for(int i=1;i<=n;i++){
        sum += pow(i, i);
    }
    cout << sum;

    return 0;
}