#include <iostream>
using namespace std;

/*
 * carry: 进位标记
 * bit_a bit_b carry_this bit_sum carry_next
 * 0     0     0          0       0
 * 0     1     0          1       0
 * 1     0     0          1       0
 * 1     1     0          0       1
 * 0     0     1          1       0
 * 0     1     1          0       1
 * 1     0     1          0       1
 * 1     1     1          1       1
 * So, bit_sum = bit_a ^ bit_b ^ carry_this
 *     carry_next = (bit_a & bit_b) | (bit_a & carry_this) | (bit_b & carry_this)
 */



int getSum(int a, int b) {
    int bit_a = 0;
    int bit_b = 0;
    int carry = 0;
    int bit_sum = 0;
    int result = 0;
    int get_bit = 1;
    int bit_pos = 0;
    while (get_bit != 0) {
        bit_a = (a & get_bit) >> bit_pos;
        bit_b = (b & get_bit) >> bit_pos;
        bit_sum = bit_a ^ bit_b ^ carry;
        
        result = result | (bit_sum << bit_pos);
        
        carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry);
        get_bit = get_bit << 1;
        bit_pos++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int a,b;
    while (true){
        cout << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        int sum = getSum(a, b);
        cout << sum << endl;
    }
    return 0;
}
