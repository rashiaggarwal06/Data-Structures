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
    TreeNode* searchBST(TreeNode* root, int val){
        //If root is empty, return NULL
        if(root == NULL) return NULL;
        //If root's value matches with the value we have to find, then return the whole root after that
        if(root->val == val) return root;
        //check if root's value is greater than the value need to find, then go to the left part of the tree, else go to the right part of the tree
        if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val) ;
    }
};