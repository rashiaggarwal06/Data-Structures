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
    void findPaths(TreeNode* root, string path, vector<string>& res){
        //when root is null
        if(root == NULL) return;
        //If path string is not empty means node is having next level, so add "->" in path string
        if(!path.empty()) 
            path += "->";
        //Add node's value as a string in path
        path += to_string(root->val);
        //If node is leaf node, then push path in the resultant vector of string
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        //Call for left subtree
        findPaths(root->left, path, res);
        //Call for right subtree
        findPaths(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        findPaths(root, "", res);
        return res;
    }
};