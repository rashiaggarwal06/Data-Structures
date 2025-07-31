class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p = 1;
        //Iterate over the array
        for(int n : nums)
            //If the element is 0, return 0 because we know that if any element in the array is zero then the product of whole array will also be 0
            if(n == 0)
                return 0;
            //Check if the number is negative, if yes then do product the variable p with -1, we are just checking the signs of the elements so that we can get relief from the overflow
            else if(n < 0)
                p *= -1;
        //else, return the same product, either it will 1 or -1
        return p;
    }
};