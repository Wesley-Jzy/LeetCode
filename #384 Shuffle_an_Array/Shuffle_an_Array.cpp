class Solution {
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = _nums;
        int len = _nums.size();
        for (int i = 0;i < len;i++) {
            int rand_pos = rand() % (len - i) + i;
            int temp = nums[rand_pos];
            nums[rand_pos] = nums[i];
            nums[i] = temp;
        }
        return nums;
    }
    
private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */