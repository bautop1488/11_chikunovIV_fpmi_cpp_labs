#include <iostream>

int* buble_sort(int* a, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]) > abs(a[j])){
                int t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }

    return a;

}

int main(){

    const int MAXSIZE = 100;
    int n;
    int a[MAXSIZE];

    std::cout << "Type n: ";

    if(!(std::cin >> n)){
        std::cout << "Invalid input";
        std::exit(1);
    }
    if(n > MAXSIZE){
        std::cout << "Error, N is too big";
        std::exit(1);
    }

    std::cout << "Type elements: ";
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }

    int* b = buble_sort(a, n);
    for(int i=0;i<n;i++){
        std::cout << b[i] << ' ';
    }

    return 0;
}