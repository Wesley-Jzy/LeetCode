class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {return 0;}
        int x = grid[0].size();
        int y = grid.size();
        //找出所有连通的两点，记录在vector< pair<int, int> > connected_edges中
        /*本来特别苦恼怎么表示边的序号，后来在discuss中看到了id = j * x + i的巧妙方法,
         学习之*/
        vector< pair<int, int> > connected_edges;
        for (int j = 0;j < y; j++) {
            for (int i = 0;i < x;i++) {
                if (grid[j][i] == '1') {
                    int here = j * x + i;
                    if (i + 1 < x) {
                        if (grid[j][i+1] == '1') {
                            int right = j * x + i + 1;
                            connected_edges.push_back(make_pair(here, right));
                        }
                    }
                    if (j + 1 < y) {
                        if (grid[j+1][i] == '1') {
                            int down = (j + 1) * x + i;
                            connected_edges.push_back(make_pair(here, down));
                        }
                    }
                }
            }
        }
        //用一个vector<int> roots记录所有边的情况，开始时roots[i] ＝ -1
        vector<int> roots(x * y, -1);
        //用connected_edges的记录_union所有边
        for (auto edge : connected_edges) {
            _union(roots, edge.first, edge.second);
        }
        //当roots[i] < 0, 且grid中为'1'时，count++
        int count = 0;
        for (int id = 0;id < x * y;id++) {
            if (roots[id] < 0 && grid[id/x][id%x] == '1') {
                count++;
            }
        }
        return count;
    }
    
    // funtion: _union(vector<int>& roots, int node1, int node2)
    // usage: 把size小的树并到size大的树里
    void _union(vector<int>& roots, int node1, int node2) {
        int pos1 = node1;
        while (roots[pos1] >= 0) {
            pos1 = roots[pos1];
        }
        int size1 = -roots[pos1];
        
        int pos2 = node2;
        while (roots[pos2] >= 0) {
            pos2 = roots[pos2];
        }
        int size2 = -roots[pos2];
        if (pos1 != pos2) {
            if (size1 <= size2) {
                roots[pos1] = pos2;
                roots[pos2] = roots[pos2] - size1;
            }
            else {
                roots[pos2] = pos1;
                roots[pos1] = roots[pos1] - size2;
            }
        }
    }
    
};