class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //make a result vector
        vector<int> res;
        //Create a frequency map 
        map<int, int> freq;
        //Count frequency of all the elements
        for(int x : nums)
            freq[x]++;
        //Find the value of the map having appearence more than [n / 3] times
        for(auto& it : freq){
            if(it.second > nums.size() / 3)
                res.push_back(it.first);
        }
        return res;
    }
};