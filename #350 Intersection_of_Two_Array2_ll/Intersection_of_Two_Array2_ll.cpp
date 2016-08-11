class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> nums_freq;
        for (int num : nums1) {
            nums_freq[num]++;
        }
        for (int num : nums2) {
            nums_freq[num]--;
            if (nums_freq[num] >= 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};