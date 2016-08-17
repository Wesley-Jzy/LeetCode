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
    int subtreeMoney(TreeNode* root, int& lc, int& rc) {
        if (!root) {return 0;}
        int lc_lc = 0, lc_rc = 0, rc_lc = 0,rc_rc = 0;
        lc = subtreeMoney(root->left, lc_lc, lc_rc);
        rc = subtreeMoney(root->right, rc_lc, rc_rc);
        return max(root->val + lc_lc + lc_rc + rc_lc + rc_rc, lc + rc);
    }
    
    int rob(TreeNode* root) {
        int lc = 0, rc = 0;
        return subtreeMoney(root, lc, rc);
    }
};