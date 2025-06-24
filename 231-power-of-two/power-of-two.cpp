class Solution {
public:
    bool power(int n, int x){
        double num = pow(2, x);
        if(num > n) return false;
        if(num == n) return true;
        return power(n, x + 1);
    }
    bool isPowerOfTwo(int n){
        if(n <= 0) return false;
        return power(n, 0);
    }
};