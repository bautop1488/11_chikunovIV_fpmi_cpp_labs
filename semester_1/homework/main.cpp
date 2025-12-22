#include <iostream>
#include "fraction.h"

int main(){
    Fraction a(10, 2);
    Fraction b(18, 3);
    Fraction c;

    Fraction r;
    r = a - b;

    r.Print();

    return 0;
}