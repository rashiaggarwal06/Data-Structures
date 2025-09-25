class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        //Create a vector last row and copy all the elements from the last row in that vector
        vector<int> l_row = t[t.size() - 1];
        //Iterate from bottom to top in the triangle vector(Use bottom-up dp approach)
        for(int i = t.size() - 2; i >= 0; i--){
            //Check every element of each row, compare values from right diagonal and straight downward, pick minimum from them and store values in last row vector
            for(int j = 0; j <= i; j++)
                l_row[j] = t[i][j] + min(l_row[j], l_row[j + 1]);
        }
        //return the first element of the last row vector, because it is the only element which is minimum path sum from top to bottom or bottom to up  
        return l_row[0];
    }
};