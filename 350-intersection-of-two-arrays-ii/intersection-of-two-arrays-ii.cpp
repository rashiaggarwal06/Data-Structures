class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        //Create a result vector to store elements 
        vector<int> res;
        //Create an unordered map to find frequencies of nums1 vector elements
        unordered_map<int, int> mp;
        //Count frequency by iterating to the nums1 vector
        for(int i : nums1){
            mp[i]++;
        }
        //Iterate over the nums2 vector
        for(int i : nums2){
            //If frequency of a particular element is more than 0, then push it into the res vector and subtract frequency by 1
            if(mp[i] > 0){
                res.push_back(i);
                mp[i]--;
            }
        }
        //Just return the res vector that contains duplicate elements
        return res;
    }
};