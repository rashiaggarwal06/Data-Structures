class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> st;
        
        //next smaller elements
        for(int i = n - 1; i >= 0; i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        //Empty the stack means remove the remaining elements from the stack
        while(!st.empty())
            st.pop();

        //previous smaller elements
        for(int i = 0; i < n; i++){
            while(st.size() > 0 && heights[st.top()] >= heights[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        //Finding the resultant value
        int res = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            res = max(res, currArea);
        }
        return res;
    }
};