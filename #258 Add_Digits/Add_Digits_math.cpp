#include <iostream>
using namespace std;

int addDigits(int num) {
    return (num-1) % 9 + 1;
}

int main(int argc, const char * argv[]) {
    int num = 0;
    while(num < 500) {
        cout << addDigits(num) << endl;
        num++;
    }
    return 0;
}
