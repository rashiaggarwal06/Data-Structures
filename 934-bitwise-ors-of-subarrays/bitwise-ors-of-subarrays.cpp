class Solution{
public:
    int subarrayBitwiseORs(std::vector<int>& arr){
        //Create a set to return the unique values only of the OR's from the given array
        unordered_set<int> res;
        unordered_set<int> curr;
        //Iterate over the array 
        for(int x : arr){
            //Make a next set that will contain the temp elements to perform functioning on every element of array
            unordered_set<int> next;
            //Insert into next set
            next.insert(x);
            //Iterate over curr set and do OR of x with each element of curr set and insert into next set 
            for(int y : curr)
                next.insert(x | y);
            //Insert the whole next array into the res set and will copy all the elements from next to curr set
            res.insert(next.begin(), next.end());
            curr = next;
        }
        //Return the size of the res set to calculate the unique present elements
        return res.size();
    }
};