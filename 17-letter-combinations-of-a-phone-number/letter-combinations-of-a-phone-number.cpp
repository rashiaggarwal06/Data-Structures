class Solution {
public:
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void keypadCombinations(string digs, int i, vector<string>& res, string comb){
        //breaking condition to push the result in vector
        if(i == digs.size()){
            res.push_back(comb);
            return;
        }
        //base case
        if(digs[i] - '0' < 2 || digs[i] - '0' > 9) return;

        //fetching the letter that we have to combine 
        string letters = keypad[digs[i] - '0'];
        for(char ch : letters)
            keypadCombinations(digs, i + 1, res, comb + ch);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res; 
        if(digits.empty()) return res;
        keypadCombinations(digits, 0, res, "");
        return res;  
    }
};