class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        makePair(result, n, 0, 0, "");
        return result;
    }
    
    void makePair(vector<string>& result, int n, int left, int right,string s) {
        if (s.length() == 2 * n) {
            result.push_back(s);
            return;
        }
        
        if (left < n) {
            makePair(result, n, left + 1, right, s + "(");
        }
        
        if (left > right) {
            makePair(result, n, left, right + 1, s + ")");
        }
    }
};