class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {return 1;}
        int fac = 9;
        for (int i = 0;i < n-1;i++) {
            fac *= (9 - i);
        }
        return fac + countNumbersWithUniqueDigits(n-1);
    }
};