#include <iostream>
#include <vector>
using namespace std;

/* split the [0,num] to [0,2),[2,4),[4,8)......
 * result[0] = 0000 = 0                           | result[1] = 0001 = 1
 * result[2] = 0010 = 0010 + 0000 = 1 + result[0] | result[3] = 0011 = 0010 + 0001 = 1 + result[1]
 * result[4] = 0100 = 0100 + 0000 = 1 + result[0] | result[5] = 0101 = 0100 + 0001 = 1 + result[1]......
 * The solution (x&(x-1)) can make the x's min 1 bit to 0;
 */

vector<int> countBits(int num) {
    vector<int> result(num+1,0);
    for (int i = 1; i <= num; i++){
        result[i] = result[i&(i-1)] + 1;
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
