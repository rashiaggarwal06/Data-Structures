class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        //use min heap to solve this problem 
        priority_queue<int, vector<int>, greater<int>> pq;
        //Iterate over the given array
        for(int i = 0; i < nums.size(); i++){
            //If priority queue has size less than k, then add elements into it until it gets to size k
            if(pq.size() < k)
                pq.push(nums[i]);
            //If we gwt k size and now the current element is greater than the queue's top element, so we just need to pop from priority queue and push current element into it
            else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        //The top element at priority queue will be the kth max element
        return pq.top();
    }
};