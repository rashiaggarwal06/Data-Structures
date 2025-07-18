class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        //Create a result vector to store elements 
        vector<int> res;
        //We will use a seen set so that we can not insert duplicate elements in our result vector
        unordered_set<int> seen;
        //Firstly, insert all the elements from nums2 to a set
        unordered_set<int> s(nums2.begin(), nums2.end());
        //Iterate over the nums1 vector now
        for(int i = 0; i < nums1.size(); i++){
            //Check if we found amy element that is common in both the nums1 and nums2 array and also it is not present in the seen set means it is unique not duplicate, if its true then just push that unique element into the result vector and insert it into the seen set to avoid duplicates for next iterations
            if(s.find(nums1[i]) != s.end() && seen.find(nums1[i]) == seen.end()){
                res.push_back(nums1[i]);
                seen.insert(nums1[i]);
            }
        }
        //Just return the res vector that contains duplicate elements
        return res;
    }
};