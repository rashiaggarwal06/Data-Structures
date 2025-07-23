class Solution{
public:
    int bagOfTokensScore(vector<int>& tokens, int power){
        //Sort the given tokens array so that we can use two-pointer approach in our array
        sort(tokens.begin(), tokens.end());
        //Make two left and right pointers to the array
        int i = 0, j = tokens.size() - 1;
        //Make 2 variables score and maxScore and set them to 0 first
        int sc = 0, maxsc = 0;
        //Start iterating from left to right or until they meet
        while(i <= j){
            //Play face-up(If current power is greater than or equal to the current element of array)
            if(power >= tokens[i]){
                //Reduce that value from power and gain score +1 and move to next value
                power -= tokens[i];
                sc++;
                //set maxScore to the max value
                maxsc = max(maxsc, sc);
                i++;
            }
            //Play face-down(If score is 1 or more and we are in array means have not exceeded out of it)
            else if(sc >= 1 && i < j){
                //Add current value to the power variable 
                power += tokens[j];
                //Reduce score by 1
                sc--;
                //Move righ side by 1
                j--;
            }
            //If both conditions does not met
            else
                break;
        }
        //Return the max Score of total play
        return maxsc;
    }
};