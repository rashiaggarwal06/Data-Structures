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
    int widthOfBinaryTree(TreeNode* root){
        //Create a queue using pair of Node and a long integer so that we reach 2^31 that is INT_MIN, there should not be memory issue, just push the root node with CBT index(Complete Binary Tree)
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});
        //Take a variable which is returning the value of the maximum width of the tree
        int maxWidth = 0;

        //Do level order traversing until the queue didn't get empty
        while(!q.empty()){
            //Store each levels size in a variable
            int k = q.size();
            //Take the index of front element of queue
            unsigned long long int stIdx = q.front().second;
            //Take the index of back element of the queue
            unsigned long long int endIdx = q.back().second;
            //Update the width and use EndIdx - startIdx + 1 so that we can find the current max. level of the tree
            maxWidth = max(maxWidth, int(endIdx - stIdx + 1));

            //Iterate k times on the queue
            for(int i = 0; i < k; i++){
                //Store the front pair {Node, index} in a auto variable and pop from the queue
                auto curr = q.front();
                q.pop();
                //If curr's left exists, then add it in the queue with index of CBT that is 2 * index + 1 (for left) 
                if(curr.first->left)
                    q.push({curr.first->left, 2 * curr.second + 1});
                //If curr's right exists, then add it in the queue with index of CBT that is 2 * index + 2 (for right) 
                if(curr.first->right)
                    q.push({curr.first->right, 2 * curr.second + 2});
            }
        }
        return maxWidth;
    }
};