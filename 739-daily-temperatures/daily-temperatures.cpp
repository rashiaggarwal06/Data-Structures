class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums){
        //Create a result vector to store elements of size n 
        vector<int> res(nums.size(), 0);
        //Make a stack to find result
        stack<int> st;
        //Iterate over the given array
        for(int i = 0; i < nums.size(); i++){
            //If stack is not empty, check if the current element is greater than the top element of the stack or not, if yes, then we will store the top element's index in a variable and pop out from stack and store a difference of (i - top element's index) into the result vector at current index position 
            while(!st.empty() && nums[i] > nums[st.top()]){
                int idx = st.top();
                st.pop();
                res[idx] = i - idx; 
            }
            //If stack is empty, push the current index into the stack
            st.push(i);
        }
        return res;
    }
};