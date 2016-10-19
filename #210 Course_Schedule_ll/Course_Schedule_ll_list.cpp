class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map< int, vector<int> > graph;
        //init
        has_circle = false;
        vector<bool> has_visited(numCourses,false);
        for (int i = 0;i < numCourses;i++) {
            vector<int> list;
            graph[i] = list;
        }
        
        //create the graph
        for (auto nodes : prerequisites) {
            graph[nodes.second].push_back(nodes.first);
        }
        
        //dfs the graph
        for (int node = 0;node < numCourses;node++) {
            if (has_circle) {
                return {};
            }
            else if (!has_visited[node]) {
                vector<bool> path(numCourses,false);
                dfs(node, graph, path, has_visited);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    void dfs(int n, map< int, vector<int> > &graph, vector<bool> &path, vector<bool> &has_visited) {
        if (has_circle) {return;}
        has_visited[n] = true;
        path[n] = true; //mark the node
        for (int i = 0;i < graph[n].size();i++) {
            int new_n = graph[n][i];
            if (path[new_n]) {
                has_circle = true;
                return;
            }
                
            else if (!has_visited[new_n]) {
                dfs(new_n, graph, path, has_visited);
            }
        }
        result.push_back(n);
        path[n] = false;
        return;
    }
    
private:
    bool has_circle;
    vector<int> result;
    
};