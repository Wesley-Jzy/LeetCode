#include <iostream>
#include <stack>
using namespace std;

//recursion solution

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
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
