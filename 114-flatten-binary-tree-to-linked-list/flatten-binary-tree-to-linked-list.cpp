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
    //Create a Next Right pointer to null globally
    TreeNode* NR = NULL;
    //Main function
    void flatten(TreeNode* root){
        //If root is null
        if(root == NULL)
            return;
        //We are going to check in reverse order of preorder to the tree, Preorder-> (root, left, right) so reverse will be (left, right, root)
        //Go to the the right first
        flatten(root->right);
        //Travese to the left then
        flatten(root->left);
        //Make its left always null because we only need to flatten tree in the right side
        root->left = NULL;
        //Make root's right to NR, attach both
        root->right = NR;
        //make NR pointer at root for updation at  every step
        NR = root;        
    }
};