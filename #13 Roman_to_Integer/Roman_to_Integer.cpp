class Solution {
public:
    int romanToInt(string s) {
        map<char,int> shift;
        shift['I']=1;
        shift['V']=5;
        shift['X']=10;
        shift['L']=50;
        shift['C']=100;
        shift['D']=500;
        shift['M']=1000;
        int sum = shift[s[0]];
        for (int i=1;i<s.length();i++) {
            sum += shift[s[i]];
            if (shift[s[i-1]] < shift[s[i]]) {sum -= (2 * shift[s[i-1]]);}
        }
        return sum;
    }
};