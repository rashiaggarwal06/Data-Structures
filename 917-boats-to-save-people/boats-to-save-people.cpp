class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit){
        //Sort the whole people array first
        sort(people.begin(), people.end());
        //Use two-pointer approach one from left and other from right
        int i = 0, j = people.size() - 1;
        //Make a variable to count the number of boats to use to shift every person and set it to 0 initially
        int minBoats = 0;
        //Iterate in between the i and j
        while(i <= j){
            //Check if first and last person can both travel in same boat or not. If yes, then move i iterator and j both, if no, then only move the j iterator
            if(people[i] + people[j] <= limit)
                i++;
            j--;
            minBoats++;
        }  
        //Return the minimum boats required 
        return minBoats;     
    }
};