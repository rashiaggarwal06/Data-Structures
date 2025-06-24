class Solution {
public:
    bool isSafe(vector<string>& b, int row, int col, int n){
        //1.Horizontal 
        for(int j = 0; j < n; j++){
            if(b[row][j] == 'Q')
                return false;
        }

        //2.Vertically 
        for(int i = 0; i < n; i++){
            if(b[i][col] == 'Q')
                return false;
        }

        //3.Left Diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(b[i][j] == 'Q')
                return false;
        }

        //4.Right Diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(b[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void nQueens(vector<string>& b, int row, int n, vector<vector<string>>& res){
        //Base Case:
        if(row == n){
            res.push_back(b);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(b, row, j, n)){
                b[row][j] = 'Q';
                nQueens(b, row + 1, n, res);
                b[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        nQueens(board, 0, n, res);
        return res;
    }
};