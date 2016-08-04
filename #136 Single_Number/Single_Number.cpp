#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i=0;i<nums.size();i++){
        result ^= nums[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,0,2,3,3,2,1,5,9,7,9,7};
    int tmp = singleNumber(nums);
    cout << "tmp=" << tmp << endl;
    return 0;
}
