// Saartaj Alam, N Queens

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){  // Returns true if the queen is in a valid position on column c.
    for (int i = 0; i < c; i++){
        if (c - i == abs(q[c] - q[i]) || q[i] == q[c]) // Row Test and Diagonal Tests
            return false;
    }
    return true;
}

int nQueens(int n){ // Returns the number of solutions to the n queens problem.
    int* q = new int[n];
    int c = 0, count = 0;
    q[c] = 0;  // q[c] represents the row on column c, so we place a queen on the first row and first column.

    while (c >= 0){     // If we reach a point where we have to backtrack from the first column, we exit the outer loop.
            c++;            // Move to the next column
            if (c == n){
                count++;     // If c = 8, then we must have a solution, and we will print it and backtrack.
                c--;          //  Otherwise, move to one before the first row.
            } else q[c] = -1;
            while (c >= 0){
                q[c]++;         // Move to the next row
                if (q[c] == n) // If the row reaches 8, then we have to backtrack by going to the previous column.
                    c--;
                else if (ok(q,c)) // Otherwise, we will return to the outer loop if the ok function returns true.
                    break;
            }
        }
        delete [] q; // Deallocate the memory previously allocated to the array.
        return count;
    }

int main(){
    int i = 1;
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem." << endl;
    }
    return 0;
}
