class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        //Create 2 variables to find the cnt of 1's and the max cnt of 1's
        int cnt = 0, mx = 0;
        //Iterate over the array
        for(int i = 0; i < nums.size(); i++){
            //If we found 1, then count += 1 and also update the mx cnt everytime 
            if(nums[i] == 1){
                cnt++;
                mx = max(mx, cnt);
            }
            //if we found any other number instead of 1, then make cnt 0 to start counting again
            else
                cnt = 0;
        }
        //return the max count of the 1's
        return mx;
    }
};