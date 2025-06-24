class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for(int i = 0; i < n; i++){
            s += nums[i];
        }
        return ((n*(n + 1)) / 2) - s; 
    }
};