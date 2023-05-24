// Saartaj Alam, Stable Marriage

#include <iostream>
using namespace std;

/*
 *  The ok function checks for 3 conflicts between the current potential matching and any one of the previous matchings.
 *  1. If the woman we are trying to match has already been matched with another man.
 *  2. If there is a mutual greater preference between the current man and any of the previous women.
 *  3. If there is a mutual greater preference between the current woman and any of the previous men.
 */
bool ok(int q[], int c){ 
    static int mp[3][3] = { { 0,2,1 },       // Man#0's preferences
                            { 0,2,1 },       // Man#1's preferences
                            { 1,2,0 } };     // Man#2's preferences
                        
    static int wp[3][3] = { { 2,1,0 },       // Woman#0's preferences
                            { 0,1,2 },       // Woman#1's preferences
                            { 2,0,1 } };     // Woman#2's preferences

    for (int i = 0; i < c; i++){
        if (q[i] == q[c] || (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) || (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c])) return false;
    }
    return true;
}

void print(int q[]){ // Print the stable matchings between each man and woman.
    static int solCount = 1;
    cout << "Solution #" << solCount++ << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; i++){
        cout << i << "\t" << q[i];
        cout << "\n";
    }
    cout << "\n\n";
}

int main(){
    int q[3] = {};
    int c = 0;
    q[0] = 0;

    while (c >= 0){     // If we reach a point where we have to backtrack from the first column, we exit the outer loop.
        c++;            // Move to the next column
        if (c == 3){ 
            print(q);     // If c = 3, then we must have a solution, and we will print it and backtrack.
            c--;          
        } else q[c] = -1; // Otherwise, move to one before the first woman.  
        while (q[c] < 3){
            q[c]++;         // Move to the next woman
            if (q[c] == 3) // If the woman index reaches 3, then we have to backtrack by going to the previous column.
                c--;
            else if (ok(q,c)) // Otherwise, we will match the current man and woman, and move on to the next man.
                break;
        }
    }
    return 0;
}
