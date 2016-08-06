#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int p_zero = 0;
    int p_other = 0;
    while (p_zero < nums.size()) {
        while (nums[p_zero] != 0 && p_zero < nums.size()) {
            p_zero++;
        }
        if (p_zero == nums.size()) {return;}
        else {
            p_other = p_zero;
            while (nums[p_other] == 0 && p_other < nums.size()){
                p_other++;
            }
            if (p_other == nums.size()) {return;}
            else {
                nums[p_zero] = nums[p_other];
                nums[p_other] = 0;
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
