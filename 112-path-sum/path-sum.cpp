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
    bool hasPathSum(TreeNode* root, int target){
        //If root is null, return false
        if(root == NULL)
            return false;
        //If its leaf node, check that the remaining value u r at is equal to target or not, if yes, true will be returned and false otherwise
        if(!root->left && !root->right)
            return target == root->val;
        //Recursively call for left subtree and right subtree
        return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
    }
};