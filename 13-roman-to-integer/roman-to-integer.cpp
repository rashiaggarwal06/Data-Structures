class Solution {
public:
    int romanToInt(string s){
        //Create a map for roman-integer values
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        //Create a variable result for storing result
        int res = 0;
        //Iterate over the whole string 
        for(int i = 0; i < s.size(); i++){
            //Take value for each element with mapped value in the created map
            int val = mp[s[i]];
            //Check if the next value is more than the current value and we are not out of bound, then subtract value from result variable
            if(i + 1 < s.size() && val < mp[s[i + 1]])
                res -= val;
            //otherwise, add value in result variable if curr value is more than next value
            else
                res += val;
        }
        return res;
    }
};