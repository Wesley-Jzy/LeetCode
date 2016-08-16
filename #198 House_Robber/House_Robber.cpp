class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {return 0;}
        if (nums.size() == 1) {return nums[0];}
        int money[nums.size()+1] = {0};
        money[1] = nums[0];
        for (int i = 2;i <= nums.size();i++) {
            money[i] = max(money[i-1],money[i-2] + nums[i-1]);
        }
        return money[nums.size()];
    }
};