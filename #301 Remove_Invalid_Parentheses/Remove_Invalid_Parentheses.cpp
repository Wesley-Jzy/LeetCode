class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> results;
        if (s.size() == 0) {
            results.push_back("");
            return results;
        }
        string left = "";
        string right = "";
        string middle = "";
        int count_l = 0;
        int count_r = 0;
        int l_pos = getLeft(s, left);
        int r_pos = getRight(s, right);
        if (l_pos >= s.size() || r_pos < 0) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '(' && s[i] != ')') {
                    middle += s[i];
                }
            }
            results.push_back(middle);
            return results;
        }
        if (l_pos - 1 == r_pos + 1) {
            left.erase(left.size() - 1);
        }
        getMiddle(s, l_pos, r_pos, middle);
        getMinNum(middle, count_l, count_r);
        if (count_l == 0 && count_r == 0) {
            results.push_back(left+middle+right);
            return results;
        }
        
        else {
            dfs(count_l, count_r, 0, 0, middle, "", left, right);
        }
        set<string>::iterator it;
        for(it = _s.begin(); it != _s.end(); it++) {
            results.push_back(*it);
        }
        return results;
    }
    
    /* remove the left ')' and right '(' */
    int getLeft (string &s, string &left) {
        int p = 0;
        while (p < s.size()) {
            if (s[p] == '(') { break; }
            if (s[p] != ')') {
                left += s[p];
            }
            p++;
        }
        return p;
    }
    
    int getRight (string &s, string &right) {
        string _right = "";
        int p = s.size() - 1;
        while (p >= 0) {
            if (s[p] == ')') { break; }
            if (s[p] != '(') {
                _right += s[p];
            }
            p--;
        }
        for (int i = _right.size() - 1; i >= 0; i--) {
            right += _right[i];
        }
        return p;
    }
    
    void getMiddle (string &s, int left, int right, string &middle) {
        for (int i = left; i <= right; i++) {
            middle += s[i];
        }
    }
    
    void getMinNum (string &s, int &count_l, int &count_r) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' ) { count_l++; }
            if(s[i] == ')' ) { count_l--; }
            if (count_l < 0) {
                count_l = 0;
                count_r++;
            }
        }
    }
    
    void dfs (int count_l, int count_r, int count, int pos, string &s, string result, string &left, string &right) {
        while (pos < s.size()) {
            if (s[pos] == '(') {
                if (count_l > 0) {dfs(count_l-1, count_r, count, pos+1, s, result, left, right);}
                count++;
            }
            else if (s[pos] == ')') {
                if (count_r > 0) {dfs(count_l, count_r-1, count, pos+1, s, result, left, right);}
                count--;
            }
            result += s[pos];
            pos++;
            if (count < 0) { return; }
        }
        if (count_l == 0 && count_r == 0) {
            _s.insert(left+result+right);
        }
    }
private:
    set<string> _s;
    
};