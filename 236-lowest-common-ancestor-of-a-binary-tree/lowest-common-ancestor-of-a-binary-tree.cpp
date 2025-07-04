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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        //Base Case:
        if(root == NULL)
            return NULL;
        
        //Check if we found value anywhere any of the value from n1 and n2
        if(root->val == n1->val || root->val == n2->val)
            return root;

        //Find the value in the left of tree and store the node
        TreeNode* leftLCA = lowestCommonAncestor(root->left, n1, n2);
        //Find the value in the right of tree and store the node
        TreeNode* rightLCA = lowestCommonAncestor(root->right, n1, n2);

        //If both left and right found values are valid, return their root
        if(leftLCA && rightLCA){
            return root;
        }

        //If left is not null, return left LCA's value
        else if(leftLCA != NULL)
            return leftLCA;

        //else, return right LCA
        else
            return rightLCA;       
    }
};