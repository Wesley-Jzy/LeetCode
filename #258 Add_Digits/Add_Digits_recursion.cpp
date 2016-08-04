#include <iostream>
using namespace std;

int addDigits(int num) {
    if (num < 10) {return num;}
    int mod = 0;
    int sum = 0;
    while(num > 0){
        mod = num % 10;
        sum += mod;
        num /= 10;
    }
    return addDigits(sum);
}

int main(int argc, const char * argv[]) {
    int num = 0;
    while(num < 500) {
        cout << addDigits(num) << endl;
        num++;
    }
    return 0;
}
