class Solution {
public:
    //Helper funtion to find the square and sum of the n
    int helper(int n){
        //Create a sum variable first
        int sum = 0;
        //Iterate until n gets 0
        while(n > 0){
            //Find last digit
            int r = n % 10;
            //Sum its square into sum variable 
            sum += r * r;
            //filter number n after removing last digit
            n /= 10;
        }
        //return sum
        return sum;
    }
    //Main function
    bool isHappy(int n) {
        //Square and until the numbers until it gets 1 or does not falls inside the loop
        while(n != 1 && n != 4){
            //Call the helper function recursively until n becomes 1 or 4
            n = helper(n);
        }
        //Return true if n == 1, otherwise false
        return n == 1;
    }
};