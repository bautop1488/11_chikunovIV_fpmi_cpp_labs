#include <iostream>

int main(){
    const int MAXSIZE = 100;
    int n, m;
    double a[MAXSIZE][MAXSIZE];

    std::cout << "Type n and m: ";
    std::cin >> n >> m;
    if(n>MAXSIZE){
        std::cout  << "Error: Array out of bounds";
        std::exit(1);
    }
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin >> a[i][j];
        }
    }

    std::cout << '\n';

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    
    return 0;
}