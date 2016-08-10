class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        unordered_map<int,int> num_freq;
        for (int num : nums) {
            num_freq[num]++;
        }
        for (auto freq : num_freq) {
            if (freq.second > n / 2){
                result = freq.first;
            }
        }
        return result;
    }
};