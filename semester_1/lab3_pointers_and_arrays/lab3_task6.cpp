#include <iostream>

int main(){
    const int MAXSIZE = 100;
    int n, p;
    int min, min_count, max_number, sum, count;
    bool lamp;
    float a[MAXSIZE], b[MAXSIZE];

    std::cout << "Type n: ";
    std::cin >> n;

    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }


    min = abs(a[0]);
    for(int i=0;i<n;i++){
        if(abs(a[i]) < min){
            min = abs(a[i]);
        }
    }
    std::cout << "minimum absolute value is " << min << std::endl;


    min_count = 0;
    for(int i=0;i<n;i++){
        if(abs(a[i]) == min){
            min_count++;
        }
    }
    if(min_count){
        max_number = 0;
        for(int i=0;i<n;i++){
            if(abs(a[i]) == min){
                max_number = i+1;
            }
        }
    }
    std::cout << "Greatest number of the minimum absolute value in array is " << max_number << std::endl;


    sum = 0;
    lamp = false;
    for(int i=0;i<n;i++){
        if(lamp){
            sum += a[i];
        }
        if(a[i] < 0){
            lamp = true;
        }
    }
    std::cout << "Sum of elements after first negative is " << sum << std::endl;


    std::cout << "Type p: ";
    std::cin >> p;

    count = 0;
    for(int i=0;i<n;i++){
        if(a[i] != p){
            b[count] = a[i];
            count++;
        }
    }
    for(int i=count;i<=n;i++){
        b[i] = 0;
    }
    for(int i=0;i<n;i++){
        std::cout << b[i] << ' ';
    }

    return 0;
}