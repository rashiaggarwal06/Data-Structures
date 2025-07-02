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
    int minDepth(TreeNode* root){
        //If we reached the end of the tree or given root is null
        if(root == NULL) return 0;
        //If left child does not exist
        if(!root->left) return minDepth(root->right) + 1;
        //if right child does not exist
        if(!root->right) return minDepth(root->left) + 1;
        //If both the child exists of root node
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};