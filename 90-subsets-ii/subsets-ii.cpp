class Solution {
public:
    void remDuplicates(vector<int>& nums, vector<vector<int>> &res, vector<int> &subs, int i){
        if(i == nums.size()){
            res.push_back(subs);
            return;
        }

        //including 
        subs.push_back(nums[i]);
        remDuplicates(nums, res, subs, i + 1);
        subs.pop_back();

        //excluding with removing duplicates
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]){
            idx++;
        }
        remDuplicates(nums, res, subs, idx);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subs;
        remDuplicates(nums, res, subs, 0);
        return res;
    }
};