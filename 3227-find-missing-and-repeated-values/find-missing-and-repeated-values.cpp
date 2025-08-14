class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //Make a res vector to store the repeated and missing both the elements
        vector<int> res(2, 0);
        //Create a frequency map to count frequency of every number
        map<int, int> freq;
        int n = grid.size();
        //Iterate over the grid and count the frequencies of all the present element
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                freq[grid[i][j]]++;
            }
        }
        //Now, Iterate n * n times starting with 1 so that we can check whiich number is missing and repeated
        for(int num = 1; num <= n * n; num++){
            //if the frequency of any number is 0, means the number is missing
            if(freq[num] == 0)
                res[1] = num;
            //If the frequency of any number is more than 1 means the number is repeated
            else if(freq[num] > 1)
                res[0] = num;
        }
        //return the resultant vector
        return res;
    } 
};