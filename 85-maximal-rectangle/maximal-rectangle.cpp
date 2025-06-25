class Solution {
public:
    // Largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        
        // Compute next smaller to the right
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while(!st.empty()) st.pop();
        
        // Compute previous smaller to the left
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        // Compute max area
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            res = max(res, heights[i] * width);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            // Build up histogram for this row
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            // Use your histogram helper
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};
