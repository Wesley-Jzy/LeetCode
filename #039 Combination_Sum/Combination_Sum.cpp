class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > results;
        vector<int> res;
        cal_result(results, res, candidates, target, candidates.size() - 1);
        return results;
    }
    
    void cal_result(vector<vector<int> >& results, vector<int>& res, vector<int> &candidates, int target,int pos) {
        if (target == 0) {
            results.push_back(res);
            return;
        }
        
        for (int i = pos;i >= 0;i--) {
            int num = candidates[i];
            if (target >= num) {
                res.push_back(num);
                if (target - num >= num) {cal_result(results, res, candidates, target - num, i);}
                else {cal_result(results, res, candidates, target - num, i - 1);}
                res.pop_back();
            }
        }
    }
};