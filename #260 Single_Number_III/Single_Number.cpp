#include <iostream>
#include <vector>
using namespace std;

//devide the array to two parts by a,b's diffent bit

vector<int> singleNumber(vector<int>& nums) {
    vector<int> result;
    int a = 0, b = 0, a_Xor_b = 0;
    for (auto num : nums) { a_Xor_b ^= num;}
    int lowest_different_bit = (a_Xor_b & (a_Xor_b-1)) ^ a_Xor_b;
    for (auto num : nums) {
        if (num & lowest_different_bit) { a ^= num;}
        else { b ^= num;}
    }
    result.push_back(a);
    result.push_back(b);
    return result;
}

int main(int argc, const char * argv[]) {
    return 0;
}
