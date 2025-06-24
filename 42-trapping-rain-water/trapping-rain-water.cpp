class Solution {
public:
    int trap(vector<int>& height){
        //Better Approach
        //TC: O(n) and SC: O(n)
        int n = height.size();
        vector<int> lmax(n, -1); //Left array
        vector<int> rmax(n, -1); //Right array
        //Initialize the leftmost and rightmost values first
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        //Starting iterating for finding the leftmost maximum value
        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i - 1], height[i]);
        }
        //Starting iterating for finding the rightmost maximum value(in reverse order)
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = max(rmax[i + 1], height[i]);
        }
        //variable to store result
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(lmax[i], rmax[i]) - height[i];
        }
        return res;
    }
};