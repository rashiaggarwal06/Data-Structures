class Solution {
public:
    int longestSubarray(vector<int>& nums){
        //Take 3 variables for calculating a window size which only contains 1 after deleting only 1 element
        int l = 0, zero_cnt = 0, res = 0;
        //use a loop to iterate over the array with a variable r 
        for(int r = 0; r < nums.size(); r++){
            //If element is 0, count zero
            if(nums[r] == 0)
                zero_cnt++;
            //if we get more than 1 zero, then shrink the window 
            while(zero_cnt > 1){
                if(nums[l] == 0) 
                    zero_cnt--;
                l++;
            }
            //Update result by checking the window size with result value
            res = max(res, r - l);
        }
        return res;
    }
};