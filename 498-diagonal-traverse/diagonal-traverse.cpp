class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat){
        int m = mat.size(), n = mat[0].size();
        //Make a result vector to store result values of size m * n means all the elements in 1 vector
        vector<int> res;
        //reserve() is used to allocate memory to the vector 
        res.reserve(m * n);
        //make two variables r and c, one for row and other for column
        int r = 0, c = 0;
        //make a boolean variable up to find either we have to move up or down
        bool up = true;
        //Iterate diagonally until the result vector fills with m * n elements
        while(res.size() < m * n){
            //Push the current element into the result vector
            res.push_back(mat[r][c]);
            //if we have to move upside in the matrix
            if(up){
                //Check if we hit the right wall, the make row + 1, and up = false because we have to move below further
                if(c == n - 1){
                    r++;
                    up = false;
                }
                //Check if the row is 0, means we have moved up and reached at row 0, then make col + 1, and up false also
                else if(r == 0){
                    c++;
                    up = false;
                }
                //Else, continue moving upside 
                else{
                    r--;
                    c++;
                }
            }
            //If up is false, means we have to move downside
            else{
                //Check if we hit the bottom boundary, make col + 1, means we have to move upside, marked up as true
                if(r == m - 1){
                    c++;
                    up = true;
                }
                //Check if the col is 0, means we hit the left wall, make row + 1 and up as true
                else if(c == 0){
                    r++;
                    up = true;
                }
                //Else, continue moving downside 
                else{
                    r++;
                    c--;
                }
            }
        }
        //return the vector result we created, as all the elements has been stored in it 
        return res;
    }
};