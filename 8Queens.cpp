#include <iostream>
using namespace std;

int main(){
    int sol_num = 1;
    int b[8][8] = {}, r = 0, c = 0;
    b[r][c] = 1;

    nc:
        c++;
        if (c == 8) goto print;
        r = -1;
        
    nr:
        r++;
        if (r == 8) goto backtrack;

        for (int i = 0; i < c; i++) {
            if (b[r][i] == 1) goto nr;
        }

        for (int i = 1; (r-i) >= 0 && (c-i) >= 0; i++){
            if (b[r-i][c-i] == 1) goto nr;
        }

        for (int i = 1; (r+i) < 8 && (c-i) >= 0; i++)
            if (b[r+i][c-i] == 1) goto nr; 

        b[r][c] = 1;
        goto nc;

    backtrack:
        c--;
        if (c == -1) return 0;

        while (r < 8 && b[r][c] != 1){
            r++;
        }
        b[r][c] = 0;
        goto nr;

    print:
        cout << "Solution #: " << sol_num++ << endl;

        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                cout << b[i][j];
            }
            cout << endl;
        }
        cout << endl;

        goto backtrack;

    return 0;
}
