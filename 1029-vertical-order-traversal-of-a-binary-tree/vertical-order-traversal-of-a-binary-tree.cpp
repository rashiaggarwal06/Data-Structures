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
    vector<vector<int>> verticalTraversal(TreeNode* root){
        //Make a vector to store result 
        vector<vector<int>> res;
        //Make a queue with tuples so that we can store node, row, col for each node
        queue<tuple<TreeNode*, int, int>> q;
        //Make a map which has col->vector of (row, val)
        map<int, vector<pair<int, int>>> mp; 
        //Push the first node as it is origin (row - 0, col - 0)
        q.push({root, 0, 0});  
        //Iterate till the queue is not empty
        while(!q.empty()){
            //Take values as node, row and col of queue's front
            auto [node, row, col] = q.front();
            //pop from the queue
            q.pop();
            //push node's data into map in the form of col = [row, node's val]
            mp[col].push_back({row, node->val});
            //If node's left exists, push it in queue with whole data
            if(node->left)
                q.push({node->left, row + 1, col - 1});
            //If node's right exists, push it in queue with whole data
            if(node->right)
                q.push({node->right, row + 1, col + 1});
        }
        //Now we are having our result in the map we have created, so iterate over the map and sort it first before taking values out from it
        for(auto& [col, vec] : mp){
            sort(vec.begin(), vec.end());
            //create a subvector to store each levels result 
            vector<int> sub;
            for(auto& [row, val] : vec)
                sub.push_back(val);
            //push the each levels result in the result vector
            res.push_back(sub);
        }
        return res;
    }
};