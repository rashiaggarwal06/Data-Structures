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
    //Create an unordered map to count max frequency
    unordered_map<int, int> mp;
    //Variable to check max frequency eeach time
    int mxFreq = 0;
    //Function to iterate over the whole tree
    void dfs(TreeNode* node){
        //If node is empty, means we are at leaf node, then simply return
        if(!node)
            return;
        //Make sure to increment the count of the node u have just traversed each time
        mp[node->val]++;
        //If the count of any element is greater than maxFreq containing frequnecy, then replace maxFreq with new max frequency
        if(mp[node->val] > mxFreq)
            mxFreq = mp[node->val];
        //Move in left subtree
        dfs(node->left);
        //Move in right subtree
        dfs(node->right);
    }
    //Main Function
    vector<int> findMode(TreeNode* root) {
        //Create a result vector to store resultant values
        vector<int> res;
        //Traverse in the whole tree
        dfs(root);
        //Iterate in the frequency map
        for(auto &p : mp){
            //If any element has frequency equals to max frequency, then push that element into the result vector
            if(p.second == mxFreq)
                res.push_back(p.first);
        }
        //Return the resultant vector
        return res;
    }
};