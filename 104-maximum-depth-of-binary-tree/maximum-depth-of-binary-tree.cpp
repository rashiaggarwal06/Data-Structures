/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root){
        //Base Case:
        if(root == NULL) return 0;
        //Find the both sides height left and right
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        //Return the maximum height from both left and right and add also add 1 because we are also adding the current level of the tree
        return max(lHeight, rHeight) + 1;
    }
};