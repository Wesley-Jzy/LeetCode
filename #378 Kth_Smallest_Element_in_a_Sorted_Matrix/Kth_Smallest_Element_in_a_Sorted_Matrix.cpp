class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int> > smallHeap;
        for (auto row : matrix) {
            for (int n : row) {
                smallHeap.push(n);
            }
        }
        for (int i=0;i<k-1;i++) {
            smallHeap.pop();
        }
        return smallHeap.top();
    }
};