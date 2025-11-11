#include <iostream>
#include <random>

void sum_after_zero(int** a, int n, int m){
    bool is_zero;
    for(int i = 0;i < n;++i){
        is_zero = false;
        for(int j = 0;j < m;++j){
            if(a[i][j] == 0){
                is_zero = true;
            }
        }
        if(!is_zero){
            int sum = 0;
            for(int j = 0;j < m;++j){
                sum += a[i][j];
            }
            std::cout << sum << ", ";
        }
    }
}

void replace_cols(int** a, int n, int m){
    for(int j = 0;j < m/2;++j){
        for(int i = 0;i < n;++i){
            int t = a[i][m-j-1];
            a[i][m-j-1] = a[i][j];
            a[i][j] = t;
        }
    }
}

void input(int& a){
    if(!(std::cin >> a)){
        throw "Incorrect input";
    }
}

void print_matrix(int** a, int n, int m){
    for(int i = 0;i < n;++i){
        std::cout << '\n';
        for(int j = 0;j < m;++j){
            std::cout << a[i][j] << ' ';
        }
    }
}

void clear_memory(int**& a, int n){
    if(a == nullptr){
        throw "error";
    }
    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int main(){
    int n, m;
    int** a = nullptr;
    
    try{
        std::cout << "Enter n and m: ";
        input(n);
        input(m);
        if(n < 0 || m < 0){
            throw "Incorrect input";
        }

        a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[m];
        }

        std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
        int random_mode = -1;
        if(!(std::cin >> random_mode) || !(random_mode==1 || random_mode==2)){
            throw "Incorrect input";
        }

        if(random_mode == 1){
            std::cout << "Type the elements of matrix:\n";
            for(int i = 0;i < n;++i){
                for(int j = 0;j < m;++j){
                    input(a[i][j]);
                }
            }
        }
        else{
            int min, max;
            std::cout << "Type the interval in which the elements of the matrix will be located.\n";
            std::cout << "Enter a: ";
            input(min);
            std::cout << "Enter b: ";
            input(max);
            if(min > max){
                throw "Incorrect input";
            }
        
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dist(min, max);
        
            for(int i = 0;i < n;++i){
                for(int j = 0;j < m;++j){
                    a[i][j] = dist(gen);
                }
            }
            print_matrix(a, n, m);
            std::cout << '\n';
        }

        std::cout << "Sums of elements in rows that dont contain 0 are ";
        sum_after_zero(a, n, m);

        replace_cols(a, n, m);

        print_matrix(a, n, m);

        clear_memory(a, n);
    }catch(const char* msg){
        if(msg == "Incorrect input"){
            std::cout << msg;
            try{
                clear_memory(a, n);
            }
            catch(const char* msg2){

            }
            std::exit(1);
        }
    }

    return 0;
}