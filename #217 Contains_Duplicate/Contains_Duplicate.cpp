class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool isDuplicate = false;
        unordered_map<int,int> num_freq;
        for (int num : nums) {
            num_freq[num]++;
            if (num_freq[num] > 1) {isDuplicate = true;}
        }
        return isDuplicate;
    }
};