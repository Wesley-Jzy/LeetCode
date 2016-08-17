class Solution {
public:
    int rob(vector<int>& nums) {
        int money = 0;
        int n = nums.size();
        if (n == 1) {return nums[0];}
        int ppre = 0, pre = 0, now = 0;
        for (int i = 0;i < n - 1;i++) {
            now = max(pre,ppre+nums[i]);
            ppre = pre;
            pre = now;
        }
        money = now;
        ppre = 0; pre = 0; now = 0;
        for (int i = 1;i < n;i++) {
            now = max(pre,ppre+nums[i]);
            ppre = pre;
            pre = now;
        }
        money = max(money,now);
        return money;
    }
};