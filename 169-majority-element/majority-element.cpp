class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // //Brute force Approach: O(n^2) 
        // //This solution is not much optimal and best 
        // for(int val : nums){
        //     int freq = 0;
        //     for(int el : nums){
        //         if(el == val) freq++;
        //     }
        //     if(freq > nums.size() / 2) return val;
        // }
        // return -1;




        // //Optimal Approach: O(n logn) + O(n) = O(n logn)s
        // sort(nums.begin(), nums.end());
        // int res = nums[0], freq = 1;
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] == nums[i - 1])
        //         freq++;
        //     else
        //         freq = 1;
        //         res = nums[i];
        //     if(freq > nums.size() / 2)
        //         return res;
        // }
        // return res;



        //Moore's Approach: O(n)
        int freq = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(freq == 0) {
                res = nums[i];
            }
            if(res == nums[i]){
                freq++;
            } 
            else{
                freq--;
            }
        }
        return res;
    }
};