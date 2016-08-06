#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int fast = 0;
    int slow = 0;
    while (fast < nums.size()) {
        if (nums[fast] != 0) {
            swap(nums[fast],nums[slow]);
            slow++;
        }
        fast++;
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
