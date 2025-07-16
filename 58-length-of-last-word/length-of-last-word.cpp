class Solution {
public:
    int lengthOfLastWord(string s){
        int l = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            //If we do not find any whitespace then we make our variable + by 1
            if(s[i] != ' ')
                l++;
            //If we found whitespace at starting in traversal means the end of string is whitespace like "Hello   World  ", we will return the length only if length is greater than 0 otherwise loop over string
            else if(l > 0)
                return l;
        }
        return l;
    }
};