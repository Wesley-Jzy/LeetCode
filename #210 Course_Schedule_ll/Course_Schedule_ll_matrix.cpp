class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > matrix(numCourses, vector<int>(numCourses));
        //init
        num = numCourses;
        has_circle = false;
        vector<bool> has_visited(num,false);
        for (int row = 0;row < num;row++) {
            for (int col = 0;col < num;col++) {
                matrix[row][col] = 0;
            }
        }
        
        //create the graph
        for (auto nodes : prerequisites) {
            matrix[nodes.second][nodes.first] = 1;
        }
        
        //dfs the graph
        for (int node = 0;node < num;node++) {
            if (has_circle) {
                return {};
            }
            else if (!has_visited[node]) {
                vector<bool> path(num,false);
                dfs(node, matrix, path, has_visited);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(int n, vector< vector<int> > &matrix, vector<bool> &path, vector<bool> &has_visited) {
        if (has_circle) {return;}
        has_visited[n] = true;
        path[n] = true; //mark the node
        for (int col = 0;col < num;col++) {
            if(matrix[n][col] == 1) {
                if (path[col]) {
                    has_circle = true;
                    return;
                }
                
                else if (!has_visited[col]) {
                    dfs(col, matrix, path, has_visited);
                }
            }
        }
        result.push_back(n);
        path[n] = false;
        return;
    }
    
private:
    int num;
    bool has_circle;
    vector<int> result;
    
};