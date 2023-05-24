// Saartaj Alam, Rat Class

#include <iostream>  
using namespace std;

// Class representing rational numberrs
class Rat {
    private:
        int n;
        int d;
    public:
        Rat(){  // default constructor
            n = 0;
            d = 1;
        }

        Rat(int i){  // conversion constructor
            n = i;
            d = 1;
        }

        Rat(int i, int j){ // Two parameter constructor
            n = i;
            d = j;
        }

        // Accessor functions (get() and set())
        int getN(){ return n;}
        int getD(){return d;}

        void setN(int i){n = i;}
        void setD(int i){d = i;}

        // Overload arithmetic operators
        Rat operator+(const Rat r){
            return Rat(n*r.d+d*r.n,d*r.d);
        }

        Rat operator-(const Rat r){
            return Rat(n*r.d-d*r.n,d*r.d);
        }

        Rat operator*(const Rat r){
            return Rat(n*r.n,d*r.d);
        }

        Rat operator/(const Rat r){
            return Rat(n*r.d,d*r.n);
        }

        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat r);
};

    // Overload of ostream operator
    // Returns a reference to an ostream object in order to chain output.
    ostream& operator<<(ostream& os, Rat r){
        if (r.n == 0)
            os << r.n;
        else if (r.n == r.d)
            os << 1;
        else if (r.n > r.d)
            os << r.n/r.d << " " << r.n%r.d << "/" << r.d; // Mixed number representation
        else
            os << r.n << "/" << r.d;
        return os;
    }

    istream& operator>>(istream& is, Rat r){
        char slash = '/';
        is >> r.n >> slash >> r.d;
        return is;
    }

int main() {
    Rat r1(1, 2), r2(3, 2);
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    
    return 0;
}
