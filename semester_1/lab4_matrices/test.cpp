#include <iostream>
#include <random>

int random(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 3);
    return dist(gen);
}

bool inc_comp(int a, int b){
    return a>=b;
}
bool dec_comp(int a, int b){
    return a<=b;
}

void bubbleSort(int* a, int n, bool(*comp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(a[j], a[j + 1])) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void merge(int *a, int left, int mid, int right, int* temp, bool(*comp)(int, int))
{
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right)
    {
        if(comp(a[i], a[j]))
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j < right)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        a[t] = temp[t];

}
void mergeSort(int* a, int left, int right, int* temp, bool(*comp)(int, int))
{
    if(right - left <= 1) return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid, temp, comp);
    mergeSort(a, mid, right, temp, comp);

    merge(a, left, mid, right, temp, comp);
}

void insertionSort(int* a, int n, bool(*comp)(int, int)) { 
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        
        while (j >= 0 && comp(a[j], key)) {
            a[j + 1] = a[j];
            j--;
        }
        
        a[j + 1] = key;
    }
}

void countingSort(int*a, int n){
    int* temp = new int(n);

    for(int i=0;i<n;i++){

    }
}

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
        std::cout << "Type the elements of matrix:\n";
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

    std::cout << "If you want to sort ascending press 1, if you want to sort descending press 2: ";
    input = -1;
    if(!(std::cin >> input) || !(input==1 || input==2)){
        std::cout  << "Incorrect input";
        std::exit(1);
    }

    bool(*comp)(int, int) = nullptr;
    if(input == 1){
        comp = inc_comp;
    }
    else{
        comp = dec_comp;
    }
    for(int i=0;i<n;i++){
        int* tmp = new int[m];
        switch(random()){
            case 1: bubbleSort(a[i], n, comp);
            case 2: mergeSort(a[i], 0, n, tmp, comp);
            case 3: insertionSort(a[i], n, comp );
        }
        delete[] tmp;
    }

    for(int i=0;i<n;i++){
        std::cout << '\n';
        for(int j=0;j<m;j++){
            std::cout << a[i][j] << ' ';
        }
    }


    delete[] a;
    return 0;

}