#include <iostream>
#include <vector>
using namespace std;

/*
 * 0 --- you lose
 * 1,2,3 --- you win
 * 4 --- you lose
 * 5,6,7 --- you can make it to 4 stones so that your opponent loses, then you win
 * 8 --- your opponent can make it to 4 stones so that you lose .......
 * We can know that 0,4,8,12...... you lose;else you win
 */

bool canWinNim(int n) {
    if ((n % 4) == 0) {return false;}
    else {return true;}
}

int main(int argc, const char * argv[]) {
    int n;
    while (true) {
        cout << "Num of stones:";
        cin >> n;
        cout << canWinNim(n) << endl;
    }
    return 0;
}
