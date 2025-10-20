#include <iostream>
#include <random>

int main(){
    int n;
    double* m = new double[n];

    std::cout << "Type n: ";
    if(!(std::cin >> n)){
        std::cout << "Invalid input, error";
        std::exit(1);
    }
    
    std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
    int input = -1;
    if(!(std::cin >> input) || !(input==1 || input==2)){
        std::cout  << "Incorrect input";
        std::exit(1);
    }

    if(input == 1){
        std::cout << "Type " << n << " elements:\n";
        for(int i=0;i<n;i++){
            std::cin >> m[i];
        }
    }
    else{
        double a, b;
        std::cout << "Type the interval in which the elements of the array will be located.\n";
        std::cout << "Type a: ";
        std::cin >> a; 
        std::cout << "Type b: ";
        std::cin >> b;
    
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(a, b);
    
        for(int i=0;i<n;i++){
            m[i] = dist(gen);
        }
        for(int i=0;i<n;i++){
            std::cout << m[i] << ' ';
        }
        std::cout << '\n';
    }

    
    int maxLength = 1;
    int currentLength = 1;
    
    for(int i=1;i<n;i++){
        if(m[i] != m[i-1]){
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }else{
            currentLength = 1;
        }
    }
    std::cout << "The length of the longest chain of consecutive distinct elements is " << maxLength << '\n';


    double sum = 0;
    bool lamp = false;
    for(int i=0;i<n;i++){
        if(lamp){
            sum += abs(m[i]);
        }
        if(m[i]==0 && !lamp){
            lamp = true;
        }
    }
    std::cout << "The sum of the absolute values of the elements located after the first zero is " << sum << '\n';

    
    int pos = 1;
    for(int i=2;i<n;i+=2){
        double temp = m[i];

        for(int j=i;j>pos;j--){
            m[j] = m[j-1];
        }
        m[pos] = temp;
        pos++;
    }
    for(int i=0;i<n;i++){
        std::cout << m[i] << ' ';
    }

    delete[] m;
    return 0;
}