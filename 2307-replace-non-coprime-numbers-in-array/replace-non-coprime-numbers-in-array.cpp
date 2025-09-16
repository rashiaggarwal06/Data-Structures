class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums){
        //Create a result vector to store resultant array
        vector<int> res;
        //Iterate over whole array
        for(int n : nums){
            //Push element in array
            res.push_back(n);
            //Iterate until res has more than 1 element
            while(res.size() > 1){
                //Try finding the gcd of last two non-coprime numbers in result vector
                int a = res.back();
                int b = res[res.size() - 2];
                int g = gcd(a, b);
                //If gcd is 1, break the loop(because numbers are coprime)
                if(g == 1) break;  
                //otherwise, Find LCM of both the numbers, then pop back from the result vector
                long long l = 1LL * a / g * b; 
                res.pop_back();
                //Replace the last element of result vector(after popping) with LCM to give a fresh vector as a result that matches with given conditions
                res.back() = (int)l;
            }
        }
        //return result
        return res;
    }
};