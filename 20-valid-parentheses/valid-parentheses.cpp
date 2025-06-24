class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            //if character is an opening bracket
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                //if closing brackets are more than opening brackets
                if(st.size() == 0)
                    return false;
                if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
                    st.pop();
                else
                    return false;
            }
        }
        //if opening brackets are more than closing brackets
        return st.size() == 0;
    }
};