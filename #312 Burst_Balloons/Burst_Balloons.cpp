class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int nums_new[n+2];
        nums_new[0] = 1;
        nums_new[n+1] = 1;
        for (int i = 0;i < n;i++) {
            nums_new[i+1] = nums[i];
        }
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for (int len = 1;len <= n;len++) {
            for (int left = 0;left <= n - len;left++) {
                int right = left + len + 1;
                for (int final = left + 1;final < right;final++) {
                    dp[left][right] = max(dp[left][right], nums_new[left] * nums_new[final] * nums_new[right] + dp[left][final] + dp[final][right]);
                }
            }
        }
        return dp[0][n+1];
    }
};