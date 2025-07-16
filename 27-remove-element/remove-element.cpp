class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        //make a variable k so that we can store values at a specific index
        int k = 0;
        //iterate over the nums vector
        for(int i = 0; i < nums.size(); i++){
            //If the current element does not matches with the value given, then we just place the current element at kth position, and if we founds the value element, then we simply increase i not k and here k will remain same as before and we can store the unmatched value at this position and the guven "val" will automatically be ignored
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        //It will store the length of new array with removed vals from original array
        return k;
    }
};