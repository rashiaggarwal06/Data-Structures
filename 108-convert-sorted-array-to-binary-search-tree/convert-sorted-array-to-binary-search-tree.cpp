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
    TreeNode* buildBST(vector<int>& nums, int l, int r){
        //If at any time left index cross right index, just return null
        if(l > r)
            return NULL;
        //Find the mid element of the array that will be root because we have given sorted array means mid element is root(inorder sequence is given)
        int m = l + (r - l) / 2;
        //Make the mid element as root
        TreeNode* root = new TreeNode(nums[m]);
        //call for left from a range left to mid - 1
        root->left = buildBST(nums, l, m - 1);
        //call for right from a range mid + 1 to right
        root->right = buildBST(nums, m + 1, r);
        //return root after building the whole tree
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        //Call the function to build BST using array, pass left and right of the given array
        return buildBST(nums, 0, nums.size() - 1);    
    }
};