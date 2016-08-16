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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {return result;}
        if (!root->left && !root->right) {
            result.push_back(root->val);
            return result;
        }
        if (root->left) {inorderTraversal(root->left);}
        result.push_back(root->val);
        if (root->right) {inorderTraversal(root->right);}
        return result;
    }
private:
    vector<int> result;
};