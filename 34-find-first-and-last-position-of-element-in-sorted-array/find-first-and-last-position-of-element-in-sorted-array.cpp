class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        //Create a result vector of size 2 only for first and last position and initialize both with -1
        vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1;
        //Finding first occurence of the element
        while(l <= r){
            //Find mid index
            int m = l + (r - l) / 2;
            //if mid element is greater than or equal to target, then find in the left half
            if(nums[m] >= target)
                r = m - 1;
            //Else, search in right half
            else
                l = m + 1;
            //If we found element matching with target, make its first index as the index value of the mid
            if (nums[m] == target) 
                res[0] = m;
        }
        //Finding last occurence of the element
        l = 0, r = nums.size() - 1;
        while(l <= r){
            //Find mid
            int m = l + (r - l) / 2;
            //If mid element is smaller than or equal to target, then search in right half
            if(nums[m] <= target)
                l = m + 1;
            //Else, search in left half
            else 
                r = m - 1;
            //If mid id equal to target, set res[1] position as the index of mid
            if(nums[m] == target) 
                res[1] = m;
        }
        //return the result vector
        return res;
    }
};