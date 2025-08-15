class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr){
        //Use two Pointers approach 
        int l = 0, r = arr.size() - 1;
        //Iterate until we left is smaller than right index
        while(l < r){
            //Find the middle element 
            int m = l + (r - l) / 2;
            //If middle element is smaller than the middle + 1 element, then shift the left pointer to mid + 1, else shift the right pointer to mid
            if(arr[m] < arr[m + 1])
                l = m + 1;
            else
                r = m;
        }
        //return the left pointer because the left is carrying the peak value
        return l;        
    }
};