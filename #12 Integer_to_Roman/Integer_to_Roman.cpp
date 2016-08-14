class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int n[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i = 0;
        while (num > 0) {
            while (num >= n[i]) {
                num -= n[i];
                result += r[i];
            }
            i++;
        }
        return result;
    }
};