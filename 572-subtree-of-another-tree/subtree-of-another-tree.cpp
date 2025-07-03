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
    //Function to check if all the further nodes of subtree are present in tree as it is or not
    bool isSame(TreeNode* root, TreeNode* subroot){
        //If both values are null means both are identical
        if(root == NULL && subroot == NULL) return true;
        //if any of the value is null, means not identical
        if(root == NULL || subroot == NULL) return false;
        //If values of nodes of tree and subtree are not equal
        if(root->val != subroot->val) return false;
        //Continue checking for next values below in the tree for left and right both
        return isSame(root->left, subroot->left) && isSame(root->right, subroot->right);  
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot){
        //If root is null or subroot is null, return they are equal if really equals it will return true else false
        if(root == NULL || subroot == NULL) return root == subroot;
        //Check the values for root and subroot and also check if the trees are same or not. If trees are same means yes subroot is subtree of the given tree
        if(root->val == subroot->val && isSame(root, subroot))
            return true;
        //Continue checking for root's left and root's right until we hit the base cases
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};