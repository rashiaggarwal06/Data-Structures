class Solution {
public:
    int maxFrequencyElements(vector<int>& nums){
        //To accomodate the largest number as an index, we will make freq vector of size maximum_element
        int mx_el = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx_el + 1, 0);
        //Find all the frequencies of elements
        for(int x : nums)
            freq[x]++;
        //Find the maximum element in the freq map
        int mx = *max_element(freq.begin(), freq.end());
        //Sum all the frequencies of freq map having value same as mx
        int res = 0;
        for(int f : freq){
            if(f == mx)
                res += f;
        }
        //return result variable
        return res;
    }
};