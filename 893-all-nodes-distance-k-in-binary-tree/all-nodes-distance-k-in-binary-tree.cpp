class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack){
        //Make a queue to iterate over the tree
        queue<TreeNode*> q;
        //Push the root element first in the queue
        q.push(root);
        //Iterate over tree till the queue gets empty
        while(!q.empty()){
            //make the queue's front node as curr and pop the queue's front 
            TreeNode* curr = q.front(); q.pop();
            //If queue's front's left exists, push it into the queue and make a key value (Node, Node) pair of child, parent
            if(curr->left != NULL){
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            //If queue's front's right exists, push it into the queue and make a key value (Node, Node) pair of child, parent
            if(curr->right != NULL){
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    //Main function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        //Make an unordered map to track the parent of every node
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        //make another map to track which element has been visited or which is not
        unordered_map<TreeNode*, bool> visited;
        //Call the parent track function to make pairs of child and parent of each node of the tree
        markParents(root, parentTrack);
        //Make a queue to iterate over the tree
        queue<TreeNode*> q;
        //Push the target element first in the queue
        q.push(target);
        //Mark it visited or true in the map visited
        visited[target] = true;
        //Take a variable current level to keep track whether we reached at k distance or not
        int curr_level = 0;
        //Iterate until queue not gets empty
        while(!q.empty()){
            //Find size of current queue
            int size = q.size();
            //If current level reachs to k then break the loop, means we found result 
            if(curr_level++ == k) break;
            //Iterate on queue for size times
            for(int i = 0; i < size; i++){
                //Make the queue's front as curr
                TreeNode* curr = q.front(); 
                q.pop();
                //Check if queue's left exists and is not visited, then push it in the queue and mark it visited in visited map
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                //Check if queue's right exists and is not visited, then push it in the queue and mark it visited in visited map
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                //Check if queue's parent exists and is not visited, then push it in the queue and mark it visited in visited map
                if (parentTrack[curr] && !visited[parentTrack[curr]]) {
                    q.push(parentTrack[curr]);
                    visited[parentTrack[curr]] = true;
                }
            }
        }
        //Make a result vector
        vector<int> res;
        //Iterate over the whole queue, because queue now only contains the elements that are result
        while(!q.empty()){
            //Push queue's front in result vector
            res.push_back(q.front()->val);
            //Pop that from queue
            q.pop();
        }
        //return result vector
        return res;
    }
};