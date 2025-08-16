class Solution {
public:
    int maximum69Number (int num){
        //Convert number to string
        string s = to_string(num);
        //Find the first character that is 6, convert it into 9, because we only have 1 swap to do
        for(char& ch : s){
            if(ch == '6'){
                ch ='9';
                break;
            }
        }
        //Return number not string 
        return stoi(s);
    }
};