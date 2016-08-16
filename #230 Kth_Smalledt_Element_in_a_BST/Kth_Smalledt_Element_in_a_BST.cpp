/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        while (!nodes.empty() || root) {
            if (root) {
                nodes.push(root);
                root = root->left;
            }
            else {
                root = nodes.top();
                nodes.pop();
                if (--k == 0) { return root->val;}
                root = root->right;
            }
        }
        return -1;
    }
};