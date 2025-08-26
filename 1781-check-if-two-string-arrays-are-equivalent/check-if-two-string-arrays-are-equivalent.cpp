class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        //take two string variables to check equality
        string w1 = "", w2 = "";
        //Concatenate whole word1 array
        for(string c : word1)
            w1 += c;
        //Concatenate whole word2 array
        for(string c : word2)
            w2 += c;
        //Check if strings are equal or not
        if(w1 == w2)
            return true;
        else
            return false;
    }
};