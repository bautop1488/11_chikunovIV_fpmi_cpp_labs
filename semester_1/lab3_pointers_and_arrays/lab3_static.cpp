#include <iostream>
#include <random>

int main(){
    const int MAXSIZE = 100;
    int n;
    double m[MAXSIZE];

    std::cout << "Type n: ";
    std::cin >> n;
    if(n>MAXSIZE){
        std::cout  << "Error: Array out of bounds";
        std::exit(1);
    }
    
    std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
    int input = -1;
    std::cin >> input;
    if(!std::cin >> input || !(input==1 || input==2)){
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
        
    }

    
    int count = 0;
    for(int i = 0; i < n; i++){
        bool lamp = true;
        for(int j=0;j<i;j++){
            if(m[i] == m[j]){
                lamp = false;
                break;
            }
        }
        if(lamp){
            count++;
        }
    }
    std::cout << "There are " << count << " different elements\n";


    int pos1,pos2;
    bool lamp = false;
    for(int i=0;i<n;i++){
        if(m[i] > 0){
            if(!lamp){
                pos1 = i;
                lamp = true;
            }
            else{
                pos2 = i;
                break;
            }
        }
    }

    int sum = 0;
    for(int i=pos1+1;i<pos2;i++){
        sum += m[i];
    }
    std::cout << "Sum of the numbers located between first and second positive elements is " << sum << '\n';

    double a, b;
    std::cout << "Type an interval, whose elements will be placed after the others.\n";
    std::cout << "Type a: ";
    std::cin >> a; 
    std::cout << "Type b: ";
    std::cin >> b; 

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if((m[j] >= a && m[j] <= b) && !(m[j + 1] >= a && m[j + 1] <= b)){
                double t = m[j];
                m[j] = m[j + 1];
                m[j + 1] = t;
            }
        }
    }

    for(int i=0;i<n;i++){
        std::cout << m[i] << ' ';
    }
    
    return 0;
}