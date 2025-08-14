class Solution {
public:
    string reverseVowels(string s){
        //Make two pointers left and right to keep track of the string
        int l = 0, r = s.size() - 1;
        //Make a character set of vowels
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        //Iterate until both left and right does not meet
        while(l < r){
            //If left character is not vowel, then shift left pointer to next element on right side means l++
            if(!vowels.count(s[l]))
                l++;
            //If right character is not vowel, then shift right pointer to next element on left side means r--
            else if(!vowels.count(s[r]))
                r--;
            //If both elements are vowels, then swap them also l++, r--
            else{
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        //Return the new string created in place
        return s;
    }
};