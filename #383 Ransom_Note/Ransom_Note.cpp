class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> char_freq;
        for (int i = 0;i < magazine.length();i++) {
            char_freq[magazine[i]]++;
        }
        for (int i = 0;i < ransomNote.length();i++) {
            char_freq[ransomNote[i]]--;
            if (char_freq[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};