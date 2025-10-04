class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int res = 0;
        while(l < r){
            int a = min(h[l], h[r]) * (r - l);
            res = max(res, a);
            if(h[l] < h[r]){
                l++;
            }
            else
                r--;
        }
        return res;
    }
};