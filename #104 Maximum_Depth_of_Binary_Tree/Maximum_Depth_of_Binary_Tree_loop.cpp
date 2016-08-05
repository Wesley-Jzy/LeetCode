#include <iostream>
#include <stack>
using namespace std;

//loop solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (!root) {return 0;}
    int max_depth = 0;
    stack<TreeNode*> node;
    node.push(root);
    stack<int> node_depth;
    node_depth.push(1);
    while (!node.empty()){
        TreeNode* now_node = node.top(); node.pop();
        int now_depth = node_depth.top(); node_depth.pop();
        if (now_node->left){
            node.push(now_node->left);
            node_depth.push(now_depth+1);
        }
        if (now_node->right){
            node.push(now_node->right);
            node_depth.push(now_depth+1);
        }
        if (!now_node->left && !now_node->right){
            if (now_depth > max_depth) {max_depth = now_depth;}
        }
    }
    return max_depth;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
