class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        int mod = 0;
        while (n > 0) {
            n--;
            mod = n % 26;
            result += (char)(mod + 65);
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
};