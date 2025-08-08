class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Overall Time complexity: O((m + n) log(m + n))
        //Trim the last n elements from nums1 array
        for(int i = 0; i < n; i++) 
            nums1.pop_back();
        //Push all the elements of nums2 into nums1
        for(int i = 0; i < n; i++)
            nums1.push_back(nums2[i]);
        //Sort the nums1 array 
        sort(nums1.begin(), nums1.end());
    }
};