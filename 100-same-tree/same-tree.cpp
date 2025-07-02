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
    bool isSameTree(TreeNode* p, TreeNode* q){
        //if both are null then it means both trees are same
        if(p == NULL && q == NULL)
            return true;
        //If one of them has got null, return false
        if(p == NULL || q == NULL)
            return false;
        //Check values of both the trees, if not same return false
        if(p->val != q->val) return false;
        //continue checking values for left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};