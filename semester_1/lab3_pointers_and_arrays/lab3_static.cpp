#include <iostream>
#include <random>

int amountOfDifferentElements(double *m, int n){
    int count = 0;
    bool is_different;
    for(int i = 0;i < n;++i){
        is_different = true;
        for(int j = 0;j < i;++j){
            if(m[i] == m[j]){
                is_different = false;
                break;
            }
        }
        if(is_different){
            count++;
        }
    }
    return count;
}

void sumBetweenPositives(double *m, int n){
    int first_positive = -1, second_positive = -1;
    bool is_first_positive_is_finded = false;
    for(int i = 0;i < n;++i){
        if(m[i] > 0){
            if(!is_first_positive_is_finded){
                first_positive = i;
                is_first_positive_is_finded = true;
            }
            else{
                second_positive = i;
                break;
            }
        }
    }

    if(first_positive == -1 || second_positive == -1){
        throw "You need at least 2 positive elements;";
    }

    double sum = 0;
    for(int i = first_positive+1;i < second_positive;i++){
        sum += m[i];
    }
    std::cout << "Sum of the numbers located between first and second positive elements is " << sum << '\n';
}

void replace(double* arr, int n, double a, double b){
    int count = 0;
    for(int k = 0;k < n;++k){
        int i;
        for(i = count;i < n;++i){
            if(arr[i] <= a || arr[i] >= b){
                count++;
                break;
            }
        }

        for(int j = i;j >= count;--j){
            if((arr[j] <= a || arr[j] >= b) && (arr[j-1] >= a && arr[j-1] <= b)){
                std::swap(arr[j], arr[j-1]);
            }
        }
    }
}

double input_check(double a){
    if(!(std::cin >> a)){
        std::cout  << "Incorrect input";
        std::exit(1);
    }
    return a;
}

void print_array(double* m, int n){
    for(int i=0;i<n;++i){
        std::cout << m[i] << ' ';
    }
}

int main(){
    const int MAXSIZE = 100;
    int n;
    double m[MAXSIZE];

    std::cout << "Enter n: ";
    n = input_check(n);
    if(n > MAXSIZE){
        std::cout  << "Error: Array out of bounds";
        std::exit(1);
    }
    
    std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
    double random_mode = -1;
    random_mode = input_check(random_mode);

    if(random_mode == 1){
        std::cout << "Enter " << n << " elements:\n";
        for(int i = 0;i < n;i++){
            m[i] = input_check(m[i]);
        }
    }
    else{
        double a, b;
        std::cout << "Enter the interval in which the elements of the array will be located.\n";
        std::cout << "Enter a: ";
        a = input_check(a);
        std::cout << "Enter b: ";
        b = input_check(b);
    
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(a, b);
    
        for(int i = 0;i < n;i++){
            m[i] = dist(gen);
        }
      
        print_array(m, n);
        std::cout << '\n';
    }
    
    std::cout << "There are " << amountOfDifferentElements(m, n) << " different elements\n";

    try{
        sumBetweenPositives(m, n);
    }
    catch(const char* msg)
    {
        std::cout << msg;
        std::exit(1);
    }

    double a, b;
    std::cout << "Enter an interval, whose elements will be placed after the others.\n";
    std::cout << "Enter a: ";
    a = input_check(a);
    std::cout << "Enter b: ";
    b = input_check(b);
    if(a > b){
        std::cout << "Left border of the interval shouldn't be greater than right border";
        std::exit(1);
    }

    replace(m, n, a, b);

    print_array(m, n);
    
    return 0;
}