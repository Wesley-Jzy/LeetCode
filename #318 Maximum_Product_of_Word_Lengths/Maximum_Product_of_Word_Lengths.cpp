class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        vector<int> mask(words.size(),0);
        for (int i = 0;i < words.size();i++) {
            for (char c : words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
            
            for (int j = 0;j < i;j++) {
                if (!(mask[i] & mask[j])) {
                    result = max(result,(int)(words[i].length() * words[j].length()));
                }
            }
        }
        return result;
    }
};