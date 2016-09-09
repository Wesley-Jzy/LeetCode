class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0;i < s.length();i++) {
            while (t[j] != s[i] && j < t.length()) {
                j++;
            }
            if (j == t.length()) {
                return false;
            }
            j++;
        }
        return true;
    }
};