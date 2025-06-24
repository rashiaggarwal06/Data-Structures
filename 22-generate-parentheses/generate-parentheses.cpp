class Solution {
public:
    void generate(int n, vector<string>& res, string curr, int open){
        if(curr.length() == 2 * n){
            res.push_back(curr);
            return;
        }
        //opening brackets
        if(open < n)
            generate(n, res, curr + '(', open + 1);
        //closing brackets
        if(curr.length() - open < open)
            generate(n, res, curr + ')', open);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, res, "", 0);
        return res;
    }
};