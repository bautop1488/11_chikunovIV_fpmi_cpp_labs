#include <iostream>
#include <random>

int* merge(int* a, int* b, int n, int m){
    int* c = new int(n+m);
    int ap = 0;
    int bp = 0;

    for(int i=0;i<=n+m;i++){
        if(a[ap] < b[bp]){
            c[ap+bp] = a[ap];
            ap++;
        }else{
            c[ap+bp] = b[bp];
            bp++;
        }
    }

    return c;
}

int main(){
    const int maxsize = 1000;
    int n, m;
    int a[maxsize], b[maxsize];

    std::cout << "Type n and m: ";
    std::cin >> n >> m;
    
    std::cout << "Type a: ";
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }

    std::cout << "Type b: ";
    for(int i=0;i<m;i++){
        std::cin >> b[i];
    }

    int* c = merge(a, b, n, m);
    for(int i=0;i<n+m;i++){
        std::cout << c[i] << ' ';
    }

    delete[] c;
    return 0;
}