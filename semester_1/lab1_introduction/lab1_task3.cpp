#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    setlocale(0, "");
   
    int n, m;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;


    for(int i=1;i<=n;i++){
        if(n % i == 0 && m % i == 0) cout << i << ", ";
    }

    return 0;
}