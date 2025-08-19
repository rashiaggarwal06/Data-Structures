class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //Variable to store result 
        long long res = 0;
        //Iterate with 2-pointers approach, keep i moving and j as starting of the 0 filled subarray and add the window size into the result
        for(int i = 0, j = 0; i < nums.size(); i++){
            //if we find a non-zero digit, then move j only
            if(nums[i] != 0)
                j = i + 1;
            //Keep adding the window size in each iteration
            res += i - j + 1;
        }
        //return the no. of subarrays we can make
        return res;
    }
};