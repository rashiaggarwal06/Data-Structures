class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int totalGas = 0, totalCost = 0;
        //St is tracking the starting point that we have to return as the answer and currGas variable is tracking the current fuel we have with us to check whether we can go further with that amount of fuel or not
        int st = 0, currGas = 0;
        //We will iterate over the given gases
        for(int i = 0; i < gas.size(); i++){
            //Count total gas
            totalGas += gas[i];
            //Count total cost
            totalCost += cost[i];
            //Count the current gas present
            currGas += (gas[i] - cost[i]);
            //if the current gas is negative means we can not move further with that amount of gas so restart with the next index and curr gas will be 0 for start
            if(currGas < 0){
                st = i + 1;
                currGas = 0;
            }
        }
        //if total Cost of iteration is more than the total gas present in all indexes just return -1 means there is no index present with surplus fuel to move further, otherwise return the starting index
        return totalCost > totalGas ? -1 : st;
    }
};