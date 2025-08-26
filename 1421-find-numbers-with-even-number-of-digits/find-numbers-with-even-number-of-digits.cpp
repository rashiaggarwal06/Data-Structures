class Solution {
public:
    int findNumbers(vector<int>& nums){
        //Create a result variable to store even counts
        int res = 0;
        //iterate over the whole array
        for(int n = 0; n < nums.size(); n++){
            //Find the length of each element from array
            int s_size = to_string(nums[n]).size();
            //If length is even, count + 1
            if(s_size % 2 == 0)
                res++;
        }
        //return even counts only
        return res;
    }
};