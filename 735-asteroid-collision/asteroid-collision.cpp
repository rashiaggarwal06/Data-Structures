class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        int n = asteroids.size();
        stack<int> st;
        //loop over the whole array
        for(int i = 0; i < n; i++){
            bool flag = false; //boolean flag to mark elements true if they destroyed and false otherwise
            //iterate when two objects are moving opposite to each other
            while(st.size() > 0 && asteroids[i] < 0 && st.top() > 0){
                //if stack's top element is smaller than array's current element, then stack's element will get collide so pop it out
                if(st.top() < -asteroids[i])
                    st.pop();
                //if stack's top element is equal to the array's element then both will get collide 
                else if(st.top() == -asteroids[i]){
                    st.pop();
                    flag = true;
                    break;
                }
                //if stack's top element is greater than the array's element, then the array's element will get collide
                else{
                    flag = true;
                    break;
                }
            }
            //if any element remaining which has not been collide yet, then push it into the stack 
            if(!flag)
                st.push(asteroids[i]);
        }
        //resultant vector which we have to return as our result containing elements those do not have affect of collision
        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};