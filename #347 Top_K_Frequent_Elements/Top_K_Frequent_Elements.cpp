class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> frequent;
        for (int num : nums) {
            frequent[num]++;
        }
        
        priority_queue<pair<int, int> > pq;
        for (auto it = frequent.begin(); it != frequent.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        
        for (int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};