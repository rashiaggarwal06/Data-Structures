class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        //We need the access of elements from both ends of the deque
        deque<int> dq;
        //Result vector to return the array of maximum elements
        vector<int> res;
        //Analyze the first window
        for(int i = 0; i < k; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        //Analyze remaining part
        for(int i = k; i < nums.size(); i++){
            //push the maximum of previous window in the resultant vector
            res.push_back(nums[dq.front()]);

            //Remove the values that are not the part of current window
            while(dq.size() > 0 && dq.front() <= i - k)
                dq.pop_front();
            
            //Remove the smaller values from the deque
            while(dq.size() > 0 && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};