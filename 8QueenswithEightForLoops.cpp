// Saartaj Alam, 8 Queens with Dumb Algorithm

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){     // Returns true if the queen is in a valid position on column c.
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || c - i == abs(q[c] - q[i]))  // Row Test and Diagonal Tests
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
                cout << 1;   // If there is a queen in row i and column j, print 1, otherwise, print 0.
            else 
                cout << 0;
        }
           cout << endl;
        }
        cout << endl;
}

int main() {
    int q[8];

    for (int i0 = 0; i0 < 8; i0++) {  // These loops generate all possible combinations of rows for the queens in the 8 columns. 
        q[0] = i0;
        for (int i1 = 0; i1 < 8; i1++) {  // If the queen in column 1 is in an invalid position, move on to the next combination. We do this for every column.
            q[1] = i1;
            if (!ok(q, 1)) continue;
            for (int i2 = 0; i2 < 8; i2++) {
                q[2] = i2;
                if (!ok(q, 2)) continue;
                for (int i3 = 0; i3 < 8; i3++) {
                    q[3] = i3;
                    if (!ok(q, 3)) continue;
                    for (int i4 = 0; i4 < 8; i4++) {
                        q[4] = i4;
                        if (!ok(q, 4)) continue;
                        for (int i5 = 0; i5 < 8; i5++) {
                            q[5] = i5;
                            if (!ok(q, 5)) continue;
                            for (int i6 = 0; i6 < 8; i6++) {
                                q[6] = i6;
                                if (!ok(q, 6)) continue;
                                for (int i7 = 0; i7 < 8; i7++) {
                                    q[7] = i7;
                                    if (ok(q, 7)) {      // If the queen is in a valid position in the last column, then we have a solution, so we wil print it.
                                        print(q);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


