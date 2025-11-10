#include <iostream>
#include <random>

void maxLength(double *m, int n){
    int maxLength = 1;
    int currentLength = 1;
    
    for(int i = 1;i < n;++i){
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
}

void sumAfterZero(double *m, int n){
    double sum = 0;
    bool is_zero_finded = false;
    for(int i = 0;i < n;++i){
        if(is_zero_finded){
            sum += abs(m[i]);
        }else if(m[i] == 0){
            is_zero_finded = true;
        }
    }
    
    if(!is_zero_finded){
        throw "You need at least 1 zero to solve the task";
    }
    std::cout << "The sum of the absolute values of the elements located after the first zero is " << sum << '\n';
}

void replace(double *m, int n){
    int pos = 1;
    for(int i = 2;i < n;i += 2){
        double temp = m[i];

        for(int j = i;j > pos;--j){
            m[j] = m[j-1];
        }
        m[pos] = temp;
        pos++;
    }
}

void input(double& a){
    if(!(std::cin >> a)){
        std::cout << "Incorrect input";
        std::exit(1);
    }
}

void print_array(double* m, int n){
    for(int i = 0;i < n;++i){
        std::cout << m[i] << ' ';
    }
}

int main(){
    int n;

    std::cout << "Enter n: ";
    if(!(std::cin >> n)){
        std::cout << "Incorrect input";
        std::exit(1);
    }

    double* m = new double[n];
    
    std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
    int random_mode = -1;
    if(!(std::cin >> random_mode) || !(random_mode==1 || random_mode==2)){
        std::cout  << "Incorrect input";
        std::exit(1);
    }

    if(random_mode == 1){
        std::cout << "Enter " << n << " elements:\n";
        for(int i = 0;i < n;++i){
            input(m[i]);
        }
    }
    else{
        double a, b;
        std::cout << "Enter the interval in which the elements of the array will be located.\n";
        std::cout << "Enter a: ";
        input(a);
        std::cout << "Enter b: ";
        input(b);
    
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(a, b);
    
        for(int i = 0;i < n;++i){
            m[i] = dist(gen);
        }
        print_array(m, n);
        std::cout << '\n';
    }

    try{
        maxLength(m, n);
        sumAfterZero(m, n);
        replace(m, n);
    }
    catch(const char* msg)
    {
        std::cout << msg;
        std::exit(1);
    }

    print_array(m, n);

    delete[] m;
    return 0;
}