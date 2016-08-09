class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;;
        }
        unordered_map<char, int> charFreq;
        for (int i=0;i<s.length();i++) {
            charFreq[s[i]]++;
            charFreq[t[i]]--;
        }
        
        for (auto pair : charFreq) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
    }
};