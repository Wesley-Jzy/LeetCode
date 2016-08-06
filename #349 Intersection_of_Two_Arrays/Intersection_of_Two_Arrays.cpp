#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_set<int> comp;
    for (int num : nums1) {
        comp.insert(num);
    }
    for (int num : nums2) {
        if (comp.find(num) != comp.end()){
            result.push_back(num);
            comp.erase(num);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
