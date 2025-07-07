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
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i = left; i <= right; i++){  // inclusive range
            if(inorder[i] == val)
                return i;
        }
        return -1;  // Should never reach here if input is valid
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        // Base Case: no nodes to construct in this subtree
        if(left > right) return NULL;

        // Step 1: Create a new root node using the current preorder element
        TreeNode* root = new TreeNode(preorder[preIdx]);
        // Step 2: Find the index of the root node in the inorder array
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        // Step 3: Move to the next element in preorder
        preIdx++;
        // Step 4: Recursively build the left and right subtrees
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);
        // Step 5: Return the constructed subtree rooted at this node
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int preIdx = 0;     // Pointer to current node in preorder
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};