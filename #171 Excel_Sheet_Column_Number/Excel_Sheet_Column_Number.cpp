class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int pos = 1;
        for (int i=s.length() - 1;i>=0;i--) {
            result += ((int)(s[i] - 'A') + 1) * pos;
            pos *= 26;
        }
        return result;
    }
    
};