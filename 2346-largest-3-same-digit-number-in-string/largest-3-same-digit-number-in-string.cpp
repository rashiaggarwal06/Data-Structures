class Solution {
public:
    string largestGoodInteger(string num){
        string res = "";
        //Take a window of sixe 3 for every iteration to the string
        for(int i = 0; i <= num.size() - 3; i++){
            //If 3 characters are same, then
            if(num[i] == num[i + 1] && num[i] == num[i + 2]){
                //Store them in a temp string with size 3
                string tmp = num.substr(i, 3);
                //If res is still empty, put temp into res string or if we found another 3 digit largest number than we stored in res previously, we will store it in res
                if(res == "" || tmp > res)
                    res = tmp;
            }
        }
        return res;
    }
};