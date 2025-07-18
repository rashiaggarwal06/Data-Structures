class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        //Make a frequency map
        unordered_map<int, int> mp;
        //Put all the elements into the map to count key: value pairs of element and frequency
        for(int x : nums)
            mp[x]++;
        //Iterate over the map and if we find value as 1 means this is the element we have to return, so we will just simply return its key which is our element
        for(auto& it : mp){
            if(it.second == 1)
                return it.first;
        }
        //else return -1, means we did not find such a element
        return -1;
    }
};