class Solution {
public:
    int minPartitions(string n) {
        int mx = INT_MIN;
        for(int i = 0; i < n.size(); i++){
            mx = max(n[i] - '0', mx);
        }
        return mx;
    }
};
