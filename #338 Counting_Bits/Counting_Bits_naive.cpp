#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num) {
    vector<int> result;
    for (int i=0;i<=num;i++){
        int dec = i;
        int mod = 0;
        int count = 0;
        while (dec > 0){
            mod = dec % 2;
            if (mod == 1) {count++;}
            dec /= 2;
        }
        result.push_back(count);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<int> result = countBits(num);
    for (int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}
