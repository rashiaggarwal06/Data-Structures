class Solution {
public:
    bool powerOfThree(int n, int x){
        if(n == 0) return false;
        if(pow(3, x) == n) return true;
        if(pow(3, x) > n) return false;
        return powerOfThree(n, x + 1);
    }
    bool isPowerOfThree(int n) {
        return powerOfThree(n, 0);
    }
};