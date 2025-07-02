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
    // void preorder(TreeNode* root, vector<int>& res){
    //     //Base Case:
    //     if(root == NULL) return;
    //     //Fetch the root value
    //     res.push_back(root->val);
    //     //Left values of tree
    //     preorder(root->left, res);
    //     //Right values of tree
    //     preorder(root->right, res);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     preorder(root, res);
    //     return res;
    // }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            // Visit the current node
            res.push_back(curr->val);
            // Push right child first so left is processed first
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return res;
    }
};