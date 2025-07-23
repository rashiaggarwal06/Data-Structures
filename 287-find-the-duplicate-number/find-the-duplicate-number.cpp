class Solution{
public:
    int findDuplicate(vector<int>& nums){
        //Create a map to store frequencies of every element into it
        unordered_map<int, int> freq;
        //Iterate over the array and count frequencies
        for(int x : nums)
            freq[x]++;
        //Now iterate over the frequency map and check if any key-value pair has value more than 1, means that is the duplicate element return it
        for(auto& m : freq){
            if(m.second > 1)
                return m.first;
        }
        //else, return -1 means we do not find any element that is duplicate
        return -1;
    }
};