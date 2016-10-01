/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int size = intervals.size();
        vector<Interval> result;
        if (size == 0) {return result;}
        
        sort(intervals.begin(), intervals.end(), comp);
        int left = intervals[0].start;
        int right = intervals[0].end;
        for (int i=1; i<size;i++) {
            if (intervals[i].start > right) {
                result.push_back(Interval(left, right));
                left = intervals[i].start;
                right = intervals[i].end;
            }
            else {
                right = max(right, intervals[i].end);
            }
        }
        result.push_back(Interval(left, right));
        return result;
    }
    
};