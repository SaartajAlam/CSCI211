// Saartaj Alam, 8 Queens 1D without goto

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){        // Returns true if the queen is in a valid position on column c.
    for (int i = 0; i < c; i++){
        if (c - i == abs(q[c] - q[i]) || q[i] == q[c]) // Row Test and Diagonal Tests
            return false;
    }
    return true;
}

void print(int q[]){        // Print the sequence of numbers in the array as well as a chessboard-like representation of the solution.
    static int solutionCount = 1;
    cout << "Solution #" << solutionCount++ << ": ";
    for (int i = 0; i < 8; i++) {
        cout << q[i];
    }
    cout << endl;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (q[j] == i)
                cout << 1;  // Print a 1 if there is a queen in this cell, otherwise print a 0.
            else
                cout << 0;
        }
           cout << endl;
        }
        cout << endl;
}

int main(){
    int q[8] = {}; // Initialize the Array
    int c = 0; // Create the column counter
    q[c] = 0;  // q[c] represents the row on column c, so we place a queen on the first row and first column.

    while (c >= 0){     // If we reach a point where we have to backtrack from the first column, we exit the outer loop
        c++;
        if (c == 8){
            print(q);     // If c = 8, then we must have a solution, so we will print it and backtrack.
            c--;          //  Otherwise, prepare for traversal through each row.  
        } else q[c] = -1;
        while (q[c] < 8){
            q[c]++;         // Move to the next row
            if (q[c] == 8) // If the row reaches 8, then we have to backtrack by going to the previous column.
                c--;
            else if (ok(q,c)) // Otherwise, we will return to the outer loop if the queen is in a valid position.
                break;
        }
    }
    return 0;
}


