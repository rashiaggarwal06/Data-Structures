class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        //Create a max-heap
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        //iterate over the whole array
        for(int i = 0; i < arr.size(); i++){
            //Push the pair of difference and the number into the priority queue
            pq.push({abs(arr[i] - x), arr[i]});
            //If it contains more than k element, then pop element from it
            if(pq.size() > k)
                pq.pop();
        }
        //Now push elements into the result vector from the priority queue until it gets empty because it only contains the resultant values at second position
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        //We need to return result in sorted manner
        sort(res.begin(), res.end());
        return res;
    }
};