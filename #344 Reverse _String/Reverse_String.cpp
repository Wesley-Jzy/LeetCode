#include <iostream>
using namespace std;

string reverseString(string s) {
    int s_len = (int)s.size();
    char temp;
    for (int i=0;i<s_len/2;i++){
        temp = s[i];
        s[i] = s[s_len-i-1];
        s[s_len-i-1] = temp;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    string s = "hello wesley";
    cout << reverseString(s);
    return 0;
}
