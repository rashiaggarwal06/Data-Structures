class Solution {
public:
//Kadane's Algorithm for maximum subarray's sum 
    int maxSubArray(vector<int>& nums) {
        int mxSum = INT_MIN, currSum = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i]; //add every coming element of the array when iterating
            mxSum = max(mxSum, currSum);
            //edge case: let suppose we are having only negative values in our given array so also the result will be negative value so after updating currSum and mxSum, this edge case we are using 
            //reset currSum to 0 if currSum becomes negative value
            if(currSum < 0) currSum = 0;
        }
        return mxSum;
    }
};