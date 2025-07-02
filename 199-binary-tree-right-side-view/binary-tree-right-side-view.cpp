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
    void lvlOrder(TreeNode* root, vector<int>& level, vector<vector<int>>& res){
        //If root is empty
        if(root == NULL) return;
        //Make a queue to push every element for each level
        queue<TreeNode*> q; 
        //Push the root element first in the queue
        q.push(root); 
        //Iterate in the tree while the queue does not get empty
        while(q.size() > 0){
            //Find the size of the current level
            int k = q.size();  
            //Clear the level
            level.clear();
            //iterate till the current level exists          
            for(int i = 0; i < k; i++){
                //Store the front value in a node and pop it out
                TreeNode* curr = q.front();
                q.pop();
                //push that value in the level vector we have created which is sub part of the resultant vector
                level.push_back(curr->val); 
                //Check further if the current nodes left exists, then push it in queue and same for the current nodes right 
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            //Push the whole current level to the result
            res.push_back(level); 
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        lvlOrder(root, level, res);
        vector<int> rightViewResult;
        for(int i = 0; i < res.size(); i++){
            rightViewResult.push_back(res[i].back());
        }
        return rightViewResult;
    }
};