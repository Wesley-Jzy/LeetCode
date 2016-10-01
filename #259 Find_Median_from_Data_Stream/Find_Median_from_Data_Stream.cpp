class MedianFinder {
public:
    MedianFinder() {
        differ = 0;
        size = 0;
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if (size == 0) {
            left_heap.push(num);
            differ++;
        }
        
        else if (size == 1) {
            int left = left_heap.top();
            if (left <= num) {
                right_heap.push(num);
            }
            else {
                left_heap.pop();
                left_heap.push(num);
                right_heap.push(left);
            }
            differ--;
        }
        
        else {
            int left = left_heap.top();
            int right = right_heap.top();
            if (differ == 0) {
                if (num <= right) {
                    left_heap.push(num);
                }
                else {
                    right_heap.pop();
                    right_heap.push(num);
                    left_heap.push(right);
                }
                differ++;
            }
            
            else if (differ == 1) {
                if (num >= left) {
                    right_heap.push(num);
                }
                else {
                    left_heap.pop();
                    left_heap.push(num);
                    right_heap.push(left);
                }
                differ--;
            }
        }
        
        size++;
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if (size == 0) {
            return 0;
        }
        double median = 0;
        double left = (double)left_heap.top();
        if (differ == 1) {
            median = left;
        }
        else if (differ == 0) {
            double right = (double)right_heap.top();
            median = (left + right) / 2;
        }
        return median;
    }
    
private:
    priority_queue<int, vector<int>, less<int> > left_heap;
    priority_queue<int, vector<int>, greater<int> > right_heap;
    int differ;
    int size;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();