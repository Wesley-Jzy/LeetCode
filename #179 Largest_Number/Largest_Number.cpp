class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        vector<string> strNums;
        get_strNums(nums, strNums);
        sort(strNums.begin(), strNums.end(), cmp);
        for (string s : strNums) {
            result += s;
        }
        if (result[0] == '0') return "0";
        return result;
    }
    
    static bool cmp (const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    }
    
    void get_strNums(vector<int>& nums, vector<string>& strNums) {
        int num = 0;
        string s = "";
        stringstream ss;
        for (int i=0;i<nums.size();i++) {
            num = nums[i];
            ss << num;
            ss >> s;
            ss.clear();
            strNums.push_back(s);
        }
        return;
    }
};