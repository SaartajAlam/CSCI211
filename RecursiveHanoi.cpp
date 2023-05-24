// Saartaj Alam, Recursive Towers of Hanoi

#include <iostream>
using namespace std;

void TowersOfHanoi(int n, char from, char to, char aux){
    if (n == 0) return;
    TowersOfHanoi(n - 1, from, aux, to);
    cout << "Move ring " << n << " from " << from << " to " << to << endl;
    TowersOfHanoi(n - 1, aux, to, from);
}

int main(){
    TowersOfHanoi(3,'A','B','C');
}
