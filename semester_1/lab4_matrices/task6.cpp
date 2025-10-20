#include <iostream>
#include <random>

int main(){
    const int MAXROWS = 100;
    const int MAXCOLS= 100;
    int n, m;
    int** a = new int*[MAXROWS];

    for(int i = 0; i < MAXROWS; i++) {
        a[i] = new int[MAXCOLS];
    }

    std::cout << "Type n and m: ";
    if(!(std::cin >> n) || !(std::cin >> m)){
        std::cout << "Invalid input, error";
        std::exit(1);
    }
    if(n>MAXROWS || m>MAXCOLS){
        std::cout  << "Error: Matrix is out of bounds";
        std::exit(1);
    }
    
    std::cout << "Do you want to manually enter elements or fill the array randomly?\nPress 1 to manually input, press 2 to random fill: ";
    int input = -1;
    if(!(std::cin >> input) || !(input==1 || input==2)){
        std::cout  << "Incorrect input";
        std::exit(1);
    }

    if(input == 1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                std::cin >> a[i][j];
            }
        }
    }
    else{
        int min, max;
        std::cout << "Type the interval in which the elements of the matrix will be located.\n";
        std::cout << "Type a: ";
        std::cin >> min; 
        std::cout << "Type b: ";
        std::cin >> max;
    
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min, max);
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j] = dist(gen);
            }
        }
        for(int i=0;i<n;i++){
            std::cout << '\n';
            for(int j=0;j<m;j++){
                std::cout << a[i][j] << ' ';
            }
        }
        std::cout << '\n';
    }

    std::cout << "Sums of elements in rows that dont contain 0 are ";
    for(int i=0;i<n;i++){
        bool lamp = true;
        for(int j=0;j<m;j++){
            if(a[i][j] == 0){
                lamp = false;
            }
        }
        if(lamp){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += a[i][j];
            }
            std::cout << sum << ", ";
        }
    }

    for(int j=0;j<m/2;j++){
        for(int i=0;i<n;i++){
            int t = a[i][m-j-1];
            a[i][m-j-1] = a[i][j];
            a[i][j] = t;
        }
    }

    for(int i=0;i<n;i++){
        std::cout << '\n';
        for(int j=0;j<m;j++){
            std::cout << a[i][j] << ' ';
        }
    }


    for(int i = 0; i < MAXROWS; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;

}