class Solution{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        //Create a min-heap to find the minimum sum pairs 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        //Create a result vector to store pairs of subarrays 
        vector<vector<int>> res;
        //Now, push every element of nums1 array with nums2's first element means pair the sum like this {sum of every x + nums2[0], 0} ans also give index of nums2's elements as we give it 0 here because we are pairing with obly the nums2's first element
        for(int x : nums1){
            pq.push({x + nums2[0], 0});
        }
        //Now, Pop out elements from the min-heap we created until k times and also note that the pq is not empty
        while(k-- && !pq.empty()){
            //Store key as sum in a variable
            int sum = pq.top().first;
            //Store value as index in a variable
            int pos = pq.top().second;
            //Push the value of nums1 and nums2 element in the form of a pair. Here sum - nums2[pos] element so that we can find the x and store it
            res.push_back({sum - nums2[pos], nums2[pos]});
            //Pop the stored pair out
            pq.pop();
            //Check if the next position means next index is present in the nums2 array. If yes, push pair {x + nums2[pos], next index} into the priority queue 
            if(pos + 1 < nums2.size()){
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }
        //Output the result vector 
        return res;
    }
};