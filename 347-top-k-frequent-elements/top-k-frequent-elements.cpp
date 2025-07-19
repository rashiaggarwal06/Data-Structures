class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        //map every value with its frequency in a unordered_map
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;
        //Create a min-heap to store pair of no. of frequencies and original values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //Iterate over the map's key-value pair
        for(auto& el : mp){
            //Push elements in priority queue if exceeds than k, then pop element out that is minimum because our priority queue is min-heap
            pq.push({el.second, el.first});
            if(pq.size() > k)
                pq.pop();
        }
        //Create a result vector and store all the elements from priority queue to result vector
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};