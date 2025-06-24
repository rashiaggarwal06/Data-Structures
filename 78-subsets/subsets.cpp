class Solution {
public:
    void getSubsets(vector<int>& nums, vector<vector<int>> &res, vector<int> &subs, int i){
        if(i == nums.size()){
            res.push_back(subs);
            return;
        }
        //including 
        subs.push_back(nums[i]);
        getSubsets(nums, res, subs, i + 1);
        subs.pop_back();
        //excluding 
        getSubsets(nums, res, subs, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
    //    vector<vector<int>> res = {{}};
    //     for(int el : nums){
    //         int n = res.size();
    //         for(int i = 0; i < n; i++){
    //             vector<int> tst = res[i];
    //             tst.push_back(el);
    //             res.push_back(tst);
    //         }
    //     }
    //     return res;
        vector<vector<int>> res;
        vector<int> subs;
        getSubsets(nums, res, subs, 0);
        return res;
    }
};