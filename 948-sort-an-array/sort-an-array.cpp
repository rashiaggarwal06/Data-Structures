class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //Create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        //Make a vector to store the result 
        vector<int> res;
        //Push all the elements into the min-heap
        for(int x : nums)
            pq.push(x);
        //Iterate until the heap gets empty and push the top element of heap one by one into the result vector 
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        //Return the result vector
        return res;
    }
};