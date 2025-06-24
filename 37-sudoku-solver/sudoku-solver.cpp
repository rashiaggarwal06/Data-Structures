class Solution {
public:
    bool isSafe(vector<vector<char>>& b, int row, int col, char d){
        //1.Horizontally
        for(int j = 0; j < 9; j++){
            if(b[row][j] == d) return false;
        }

        //2.Vertically
        for(int i = 0; i < 9; i++){
            if(b[i][col] == d) return false;
        }

        //3.Grid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for(int i = sr; i <= sr + 2; i++){
            for(int j = sc; j <= sc + 2; j++){
                if(b[i][j] == d) return false;
            }
        }

        //else we are returning true
        return true;
    }

    bool helper(vector<vector<char>>& b, int r, int c){
        //Base Case:
        if(r == 9) return true;

        //We are updating our next rows and columns accordingly
        int nextR = r, nextC = c + 1;
        if(nextC == 9){
            nextR = r + 1;
            nextC = 0;
        }

        //If the cell has already any digit present
        if(b[r][c] != '.')
            return helper(b, nextR, nextC);

        //Now we are trying to fill the digits in empty cells
        for(char dig = '1'; dig <= '9'; dig++){
            if(isSafe(b, r, c, dig)){
                b[r][c] = dig;
                if(helper(b, nextR, nextC))
                    return true;
                b[r][c] = '.';
            }
        }
        //else return false 
        return false;
    }

    //Main function
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};