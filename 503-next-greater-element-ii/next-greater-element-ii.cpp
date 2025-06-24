class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        //resultant vector to store elements
        int n = nums.size();
        vector<int> res(n, 0); 
        stack<int> st;
        //Start iterating from 2 * nth element in reverse order
        for(int i = 2 * n - 1; i >= 0; i--){
            while(st.size() > 0 && nums[st.top()] <= nums[i % n])
                st.pop();
            res[i % n] = st.empty() ? -1 : nums[st.top()];
            st.push(i % n); // valid index for circular iteration
        }
        return res;
    }
};