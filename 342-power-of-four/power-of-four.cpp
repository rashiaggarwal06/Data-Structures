class Solution {
public:
    bool powerOfFour(int n, int x){
        if(n == 1) return true;
        if(pow(4, x) == n) return true;
        if(pow(4, x) > n) return false;
        return powerOfFour(n, x + 1);
    }
    bool isPowerOfFour(int n) {
        return powerOfFour(n, 0);
    }
};