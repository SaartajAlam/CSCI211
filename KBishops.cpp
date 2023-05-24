// Saartaj Alam, K Bishops on nxn board, where k <= n

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
   for (int i = 0; i < c; i++)                       // For each previous bishop,
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) return false; // if the row difference is the same as the column difference, return false.
   return true;
}

int kBishops(int n, int k) {
    int solutions = 0; // add a counter
    int* q = new int[k];
    int c = 0;
    q[c] = 0;
    
    while (c >= 0) {
        c++; // NEXT BISHOP
        if (c == k) {
            solutions++; // increment solution count
            c--; // backtrack to look for next solution
        }
        else
            q[c] = q[c-1];
        // Position-loop (q[c]-loop)
        while (c >= 0) {
            q[c]++; // NEXT SQUARE
            if (q[c] == n * n) 
                c--; // backtrack
            else if (ok(q, c, n)) break;
        }
    }
    // free up the memory in heap
    delete [] q;
    return solutions; //Return the number of solutions found.
}

int main() {
    int n, k;
    while (true){    
        cout << "Enter value of n: ";
        cin >> n;
        if (n == -1)
            return 0;
        cout << "Enter value of k: ";
        cin >> k;
        cout << "number of solutions: " << kBishops(n, k) << "\n";
    }
    return 0;
}
