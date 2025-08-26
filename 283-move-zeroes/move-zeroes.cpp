class Solution {
public:
    void moveZeroes(vector<int>& nums){
        //make two variables to loop over the array
        int l = 0, r = 0;
        //iterate over the array until r < length of array
        while(r < nums.size()){
            //Check if a[l] is 0 and also a[r] is not 0, if yes, swap a[l] and a[r], do l + 1
            if(nums[l] == 0 && nums[r] != 0){
                swap(nums[l], nums[r]);
                l++;
            }
            //If a[l] is not 0, move l + 1
            if(nums[l] != 0)
                l++;
            //Do r + 1 every time to move further in the array
            r++;
        }        
    }
};