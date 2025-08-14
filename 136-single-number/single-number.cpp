class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Take a variable XOR to xor all the numbers from the array
        int XOR = 0;
        //This loop is helping us to find the single number do not having any duplicate
        for(int i = 0; i < nums.size(); i++)
            XOR ^= nums[i];
        //We are returning that number at last
        return XOR;
    }
};