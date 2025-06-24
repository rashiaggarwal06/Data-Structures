class Solution {
public:
    bool isPalindrome(int x) {
        //all the negative numbers are non-palindromic so return false
        if(x < 0) return false;
        //save the original number somewhere first
        int o = x;
        //make a result variable to compare the original with result
        long long res = 0;
        while(x > 0){
            int r = x % 10;
            res = res * 10 + r;
            x /= 10;
        }
        return o == res; 
    }
};