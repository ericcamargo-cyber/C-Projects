#ifndef complex_H
#define complex_H

#include <iostream>

using std::ostream;

struct complex {

    complex(int = 0, int = 1);

    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(int) const;
    complex operator-(int) const;
    complex operator*(int) const;
    complex operator/(int) const;

    friend complex operator+(int, const complex &);
    friend complex operator-(int, const complex &);
    friend complex operator*(int, const complex &);
    friend complex operator/(int, const complex &);

    friend ostream &operator<<(ostream &, const complex &);

private:

    int imaginary;
    int real;
};

#endif /* complex_H */

/* complex.cc */

#include <iostream>
#include "complex.h"

complex::complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

complex complex::operator+(const complex &o) const {

    return complex(real  + o.real, imaginary + o.imaginary);
    
}

complex complex::operator+(int n) const {

    return complex(real + n, imaginary);//imaginary);
}

complex complex::operator-(const complex &o) const {

    return complex(real - o.real, imaginary - o.imaginary);
}

complex complex::operator-(int n) const {

    return complex(real - n , imaginary);
}

complex complex::operator*(const complex &o) const {

    return complex(real * o.real - (imaginary * o.imaginary), (real * o.imaginary) + (o.real * imaginary));
}

complex complex::operator*(int n) const {

    return complex(real * n, imaginary * n);
}

complex complex::operator/(const complex &o) const {

    return complex((real * o.real + (imaginary * o.imaginary))/(o.imaginary*o.imaginary+1), (real * o.imaginary * -1) + (o.real * imaginary));//return complex((real * o.real + (imaginary * o.imaginary)), (real * o.imaginary * -1) + (o.real * imaginary));
}

complex complex::operator/(int n) const {

    return complex(real, imaginary * n);
}

complex operator+(int n, const complex &o) {

    return o + n;
}

complex operator-(int n, const complex &o) {

    return complex(n) - o;
}

complex operator*(int n, const complex &o) {

    return o * n;
}

complex operator/(int n, const complex &o) {

    return complex(n) / o;
}

ostream &operator<<(ostream &out, const complex &o) {

    out << '(' <<o.real << " + " << o.imaginary << "i" << ')';
    return out;
}

/* main.cc */

#include <iostream>
#include "complex.h"

using std::cout;
using std::endl;

int main(void) {

    complex a(1, 2);
    complex b(1, 3);

    int i = 5;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    cout << a << " + " << i << " = " << a + i << endl;
    cout << a << " - " << i << " = " << a - i << endl;
    cout << a << " * " << i << " = " << a * i << endl;
    cout << a << " / " << i << " = " << a / i << endl;

    cout << i << " + " << a << " = " << i + a << endl;
    cout << i << " - " << a << " = " << i - a << endl;
    cout << i << " * " << a << " = " << i * a << endl;
    cout << i << " / " << a << " = " << i / a << endl;

    return 0;
}

