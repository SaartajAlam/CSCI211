// Saartaj Alam, 8 Numbers In A Cross

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   static int helper[8][5] = { // Each row of the helper array represents a list of neighbors for the corresponding position in the cross.
        {-1},
        {0,-1},
        {0,-1},                                   // 01
        {0,1,2,-1},                              // 2345
        {0,1,3,-1},                               // 67
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1}
    };

   for (int i = 0; i < c; i++) // Checks if the number we are currently trying to place has already been used.
      if (q[i] == q[c]) return false;

   for (int i = 0; helper[c][i] != -1; i++) // Checks if the number we are currently trying to place is consecutive to the numbers in adjacent squares.
      if (abs(q[c] - q[helper[c][i]]) == 1) return false;

   return true;
}

void print(int q[]){        // Print the sequence of numbers in the array as well as a cross to represent the solution.
    static int solCount = 1;
    cout << "Solution #: " << solCount++ << "\n";
    for (int i = 0; i < 8; i++){
        cout << q[i] << " ";
    }
    cout << "\n\n";
    cout << " "  << q[0] << q[1] << "\n";
    cout << q[2] << q[3] << q[4] << q[5] << "\n";
    cout << " "  << q[6] << q[7] << "\n\n";
}

int main(){
    int q[8] = {0}; // Initialize the Array
    int c = 0;   // Declare the column counter
    q[c] = 1;  // q[c] represents the number placed on column c, so we place a 1 on the first column.

    while (c >= 0){     // If we reach a point where we have to backtrack from the first column, we exit the outer loop.
        c++;            // Move to the next column
        if (c == 8){
            print(q);     // If c = 8, then we must have a solution, and we will print it and backtrack.
            c--;          //  Otherwise, move to one before the first number.
        } else q[c] = 0;
        while (q[c] <= 8){
            q[c]++;         // Move to the next number
            if (q[c] == 9) // If the number reaches 9, then we are out of bounds, so we backtrack.
                c--;
            else if (ok(q,c)) // If we are able to successfully place a number, we move on to the next column.
                break;
        }
    }
    return 0;
}
