class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& res){
        //Base Case:
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            getPerms(nums, idx + 1, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getPerms(nums, 0, res);
        return res;
    }
};