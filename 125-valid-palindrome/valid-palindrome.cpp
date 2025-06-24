class Solution {
public:
    bool isPalindrome(string s){

        //Base Case
        if(s.empty()) return true;

        //Remove all the other characters except alphabets, convert to lowercase also
        string fil_s = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i]))
                fil_s += tolower(s[i]);
        }

        //check for palindrome using two pointers approach
        int l = 0, r = fil_s.size() - 1;
        while(l <= r){
            if(fil_s[l] != fil_s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};