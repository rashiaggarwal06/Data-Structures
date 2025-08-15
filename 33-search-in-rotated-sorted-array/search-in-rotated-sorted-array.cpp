class Solution {
public:
    int search(vector<int>& nums, int target){
        //Use two pointers approach to find the element matches with target
        int l = 0, r = nums.size() - 1;
        //Iterate until left is smaller than or equal to right
        while(l <= r){
            //Find the middle index first to divide the array into two halves
            int m = l + (r - l) / 2;
            //If we found the target element at the middle position, return the middle index
            if(nums[m] == target) return m;
            //If the left half of the array is sorted
            else if(nums[m] >= nums[l]){
                //Target is present in between left and mid, then shift right pointer to mid - 1, otherwise shift left pointer to mid + 1
                if(nums[l] <= target && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            //If the right half of the array is sorted
            else{
                //Target is present in between mid and right, then shift left pointer to mid + 1, otherwise shift right pointer to mid - 1
                if(nums[m] <= target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        //If we do not found target at any position, return -1 means we didn't find the target
        return -1;
    }
};