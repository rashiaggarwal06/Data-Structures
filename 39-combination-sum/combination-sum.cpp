class Solution {
public:
    void combSum(vector<int>& arr, int i, vector<int>& comb, set<vector<int>>& res, int t){
        //Base Cases:
        int n = arr.size();
        if(i == n || t < 0)
            return;
        if(t == 0){
            res.insert(comb);
            return;
        }

        comb.push_back(arr[i]);
        //include single time
        combSum(arr, i + 1, comb, res, t - arr[i]);

        //include multiple times
        combSum(arr, i, comb, res, t - arr[i]);

        comb.pop_back();
        //exclude   
        combSum(arr, i + 1, comb, res, t);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        set<vector<int>> res;
        vector<int> comb;
        combSum(arr, 0, comb, res, t);
        return vector<vector<int>>(res.begin(), res.end());
    }
};