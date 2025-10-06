class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat){
        //Find number of rows and columns
        int n = mat.size(), m = mat[0].size();
        //Create a result vector of the same size as the given matrix
        vector<vector<int>> res(m, vector<int>(n));
        //Iterate over the rows one by one
        for(int i = 0; i < n; i++){
            //Iterate over the cols one by one
            for(int j = 0; j < m; j++){
                //Replace res[col][row] with matrix[row][col]
                res[j][i] = mat[i][j];
            }
        }
        //return the result vector
        return res;
    }
};