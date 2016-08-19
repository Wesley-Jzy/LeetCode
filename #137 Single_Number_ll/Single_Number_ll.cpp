class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int pos = 0;
        while (pos <= 31) {
            int sum = 0;
            for (int num : nums) {
                sum += ((num >> pos) & 1);
            }
            result = result | ((sum % 3) << pos);
            pos++;
        }
        return result;
    }
};