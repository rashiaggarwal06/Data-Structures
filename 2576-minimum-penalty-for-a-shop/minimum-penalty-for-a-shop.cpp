class Solution {
public:
    int bestClosingTime(string customers) {
        //Count total Y's in the string first to keep track
        int totalY = 0;
        for(char c : customers){
            if(c == 'Y')
                totalY++;
        }
        //Check whether any Y is present in the string or not, If no then return 0 as the best time to shut the shop
        if(totalY == 0) 
            return 0;
        //Keep track of N's in the string
        int prefixN = 0;
        //Set minimum penalty as totalY
        int min_penalty = totalY;
        //Variable to store best time to close the shop
        int best_tym = 0;
        //Iterate over the entire cuctomers string
        for(int i = 0; i < customers.length(); i++){
            //If N comes, then increase prefixN by 1
            if(customers[i] == 'N')
                prefixN++;
            //If Y comes, then decrease totalY by 1
            else if (customers[i] == 'Y')
                totalY--;
            //Count total penalty
            int penalty = prefixN + totalY;
            //Chk whether tottal penalty is minimum than min_penalty, if yes then set total penalty as min_penalty and set best time as i + 1 (means after the current customer)
            if(penalty < min_penalty){
                min_penalty = penalty;
                best_tym = i + 1;
            }
        }
        //Return the best time to close the shop
        return best_tym;   
    }
};