class Solution {
public:
    int climbStairs(int n) {
        // Base cases for 1, 2, or 3 steps
        if(n == 1 || n == 2 || n == 3)
            return n;
        // Initialize with known values:
        // b = f(2) = 2 (ways to climb 2 stairs)
        // a = f(3) = 3 (ways to climb 3 stairs)
        int a = 3, b = 2;
        // We already have f(3), so we only need to compute from f(4) to f(n)
        // That’s (n - 3) steps to compute
        for(int i = 0; i < n - 3; i++) {
            a = a + b;   // new f(n) = f(n-1) + f(n-2)
            b = a - b;   // update b to previous f(n-1)
        }
        // a now contains f(n), the number of ways to climb n stairs
        return a;
    }
};