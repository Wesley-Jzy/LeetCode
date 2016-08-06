#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int>::iterator iter_zero = nums.begin();
    vector<int>::iterator iter_other = nums.begin();
    while (iter_other != nums.end() && iter_zero != nums.end()) {
        while ((*iter_zero) != 0 && iter_zero != nums.end()) {
            iter_zero++;
        }
        if (iter_zero != nums.end()) {
            iter_other = iter_zero;
            while ((*iter_other) == 0 && iter_other != nums.end()) {
                iter_other++;
            }
            if (iter_other != nums.end()){
                *iter_zero = *iter_other;
                *iter_other = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,0,0,0,2,0,1,2,0,4,0,0,0};
    moveZeroes(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    return 0;
}
