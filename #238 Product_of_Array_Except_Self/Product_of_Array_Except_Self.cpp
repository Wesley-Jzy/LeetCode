#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = (int)nums.size();
    vector<int> output(size,1);
    /* calculate left product */
    int left_product = 1;
    for (int i=1;i<size;i++) {
        left_product *= nums[i-1];
        output[i] *= left_product;
    }
    /* calculate right product */
    int right_product = 1;
    for (int i=size-2;i>=0;i--) {
        right_product *= nums[i+1];
        output[i] *= right_product;
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,4,3,2,5};
    vector<int> output = productExceptSelf(nums);
    for (auto num : output) {cout << num << " ";}
    return 0;
}
