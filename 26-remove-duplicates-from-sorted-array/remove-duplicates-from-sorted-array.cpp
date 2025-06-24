class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                nums[idx++] = nums[i];
            }
        }
        // int rem = n - nums.size();
        // for(int i = 0; i < rem; i++){
        //     nums.push_back('_');
        // }
        return idx;
    }
};