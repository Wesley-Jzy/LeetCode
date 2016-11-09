class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum[n];
        int count[n];
        sum[0] = nums[0];
        count[0] = nums[0];
        for (int i = 1; i < n; i++) {
            count[i] = max(count[i-1]+nums[i], nums[i]);
            sum[i] = max(sum[i-1],count[i]);
        }
        return sum[n-1];
    }
    
};