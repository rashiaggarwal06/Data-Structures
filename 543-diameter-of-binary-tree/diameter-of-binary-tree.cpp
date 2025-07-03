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
    int res = 0;
    //Height function to calculate the height of a tree
    int height(TreeNode* root){
        //Base Case:
        if(root == NULL)
            return 0;
        //Calculate left part's height
        int lHeight = height(root->left);
        //Calculate right part's height
        int rHeight = height(root->right);
        //Every time update the value of res variable created to count the maximum diameter of every node 
        res = max(res, lHeight + rHeight);
        //Return the max height of the tree 
        return max(lHeight, rHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root){
        //Call height function to execute
        height(root);
        //Return res which is declared globally
        return res;        
    }
};