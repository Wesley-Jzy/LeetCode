class Solution {
public:
    int totalNQueens(int n) {
        _count = 0;
        dfs(0, n);
        return _count;
    }
    
    void dfs(int y, int n) {
        if (y == n) {
            _count++;
            return;
        }
        
        for (int x=0;x<n;x++) {
            bool is_rightPos = true;
            pair<int,int> pos_now = make_pair(x,y);
            for (auto pos : _path) {
                if (is_conflicting(pos, pos_now)) {
                    is_rightPos = false;
                    break;
                }
            }
            if (is_rightPos) {
                _path.push_back(pos_now);
                dfs(y + 1, n);
                _path.pop_back();
            }
        }
    }
    
    bool is_conflicting(pair<int,int> pos_a, pair<int,int> pos_b) {
        if (pos_a.first == pos_b.first || pos_a.second == pos_b.second || abs(pos_a.first - pos_b.first) == abs(pos_a.second - pos_b.second)) {return true;}
        return false;
    }
    
private:
    int _count;
    vector< pair<int,int> > _path;
};