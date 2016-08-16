class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count[target+1] = {0};
        count[0] = 1;
        for (int i = 1;i <= target;i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    count[i] += count[i - num];
                }
            }
        }
        return count[target];
    }
};