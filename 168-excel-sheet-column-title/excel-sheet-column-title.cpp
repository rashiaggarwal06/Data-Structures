class Solution {
public:
    string convertToTitle(int columnNumber) {
        //Initialize an empty string to store the result
        string res = "";          
        //Loop until the columnNumber is reduced to 0
        while(columnNumber > 0){
            //Decrease columnNumber by 1 to adjust for 1-based indexing
            columnNumber--;              
            //Get the remainder when dividing columnNumber by 26, It gives the corresponding character in the alphabet (A = 0, B = 1, ..., Z = 25)
            //Convert number into character and prepend into the result string
            res = char(columnNumber % 26 + 'A') + res;  
            //Divide columnNumber by 26
            columnNumber /= 26;  
        }
        //return the resultant string res
        return res;  
    }
};
