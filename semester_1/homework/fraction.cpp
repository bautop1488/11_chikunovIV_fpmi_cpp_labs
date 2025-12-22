#include <iostream>
#include "fraction.h"

int GCD(int a, int b){
    if(b > a){std::swap(a, b);}
    for(int j =1 ;j < b;++j){
        if(b%j == 0 && a % (b/j) == 0){
            return b/j;
        }
    }
    return 1;
}
int LCM(int a, int b){
    if(b > a){std::swap(a, b);}
    for(int i = 1;i < b;++i){
        if(a*i % b == 0){
            return a*i;
        }
    }
    return a*b;
}
void Reduce(int& n, int& d){
    int gcd = GCD(n, d);
    n = n/gcd;
    d = d/gcd;
}

Fraction::Fraction(): num__(0), denom__(1){}
Fraction::Fraction(int n, int d = 1){
    if(d == 0){
        throw "Denominator can't be zero";
    }
    Reduce(n, d);
    num__ = n;
    denom__ = d;
}

Fraction Fraction::operator+(const Fraction& f){
    Fraction res;
    if(f.denom__ == denom__){
        res.num__ = num__ + f.num__;
        res.denom__ = denom__;
    }
    else{
        int new_denom = LCM(denom__, f.denom__);
        res.num__ = num__*new_denom/denom__ + f.num__*new_denom/f.denom__;
        res.denom__ = new_denom;
    }
    
    return res;
}
Fraction Fraction::operator-(const Fraction& f){
    Fraction res;
    if(f.denom__ == denom__){
        res.num__ = num__ - f.num__;
        res.denom__ = denom__;
    }
    else{
        int new_denom = LCM(denom__, f.denom__);
        res.num__ = num__*new_denom/denom__ - f.num__*new_denom/f.denom__;
        res.denom__ = new_denom;
    }
    
    return res;
}
Fraction Fraction::operator*(const Fraction& f){
    Fraction res;
    res.num__ = num__ * f.num__;
    res.denom__ = denom__ * f.denom__;
    
    return res;
}
Fraction Fraction::operator/(const Fraction& f){
    Fraction res;
    res.num__ = num__ * f.denom__;
    res.denom__ = denom__ * f.num__;
    
    return res;
}

Fraction& Fraction::operator+=(const Fraction f){
    *this = *this + f;
    return *this;
}
Fraction& Fraction::operator-=(const Fraction f){
    *this = *this - f;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction f){
    *this = *this * f;
    return *this;
}
Fraction& Fraction::operator/=(const Fraction f){
    *this = *this / f;
    return *this;
}
Fraction& Fraction::operator=(const Fraction f){
    if(this == &f){return *this;}
    num__ = f.num__;
    denom__ = f.denom__;
    return *this;
}

bool Fraction::operator==(const Fraction f){
    if(this == &f){
        return true;
    }
    if(num__ == f.num__ && denom__ == f.denom__){
        return true;
    }
    return false;
}
bool Fraction::operator>(const Fraction f){
    if((*this - f).num__ > 0){
        return true;
    }
    return false;
}
bool Fraction::operator<(const Fraction f){
    if((*this - f).num__ < 0){
        return true;
    }
    return false;
}
bool Fraction::operator>=(const Fraction f){
    if((*this - f).num__ >= 0){
        return true;
    }
    return false;
}
bool Fraction::operator<=(const Fraction f){
    if((*this - f).num__ <= 0){
        return true;
    }
    return false;
}

void Fraction::Print(){
    std::cout << this->num__ << '/' << this->denom__ << std::endl;
}
