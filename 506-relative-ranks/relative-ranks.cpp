class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score){
        //Create a string vector to return 
        vector<string> res(score.size());
        //Make a max-heap to store the element based on highest marks first then 2nd highest then 3rd and so on.
        priority_queue<pair<int, int>> pq;
        //Pusn every pair of element and its original index into the max-heap
        for(int i = 0; i < score.size(); i++)
            pq.push({score[i], i});
        //Initialize a rank value to 1
        int rank = 1;
        //Iterate until the max-heap gets empty
        while(!pq.empty()){
            //Store its index somewhere in a variable so that we can make changes at that index of the result vector
            int idx = pq.top().second;
            //Pop the pair from the heap
            pq.pop();
            //If rank = 1, means the marks are highest make that index's value "Gold Medal"
            if(rank == 1)
                res[idx] = "Gold Medal";
            //If rank = 2, means the marks are second highest make that index's value "Silver Medal"
            else if(rank == 2)
                res[idx] = "Silver Medal";
            //If rank = 3, means the marks are third highest make that index's value "Bronze Medal"
            else if(rank == 3)
                res[idx] = "Bronze Medal";
            //else make the further values as same it was but convert their rank into string before storing them into the result vector
            else
                res[idx] = to_string(rank);
            //Every time increase the rank value with 1
            rank++;
        }
        //Return the string result vector  
        return res;
    }
};