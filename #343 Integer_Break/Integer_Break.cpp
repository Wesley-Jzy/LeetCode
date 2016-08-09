class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {return 1;}
        if (n == 3) {return 2;}
        int mul = 1;
        while (n >= 5) {
            n -= 3;
            mul *= 3;
        }
        mul *= n;
        return mul;
    }
};