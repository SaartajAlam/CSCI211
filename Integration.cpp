// Saartaj Alam, Integration

#include <iostream>
using namespace std;

typedef double (*FUNC)(double); // Define a function pointer type FUNC that takes a double and returns a double.


// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles
// and adding up the areas of the individual rectangles.
// Create a loop where x goes from a to b.
// x is the horizontal position of the rectangle, and f(x) is the height.
double integrate(FUNC f, double a, double b) { 
   double sum = 0;
   double dx = 0.000001;
   double x = a;
   while (x < b){
      sum += (f(x)*dx);
      x += dx;
   }
   return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}

