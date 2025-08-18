class Solution {
public:
    void sortColors(vector<int>& arr){
        //Start with 3 variables low, mid, and high
        int low = 0, mid = 0, high = arr.size() - 1;
        //iterate until mid is smaller than or equal to high
        while(mid <= high){
            //If mid is 0, swap mid with low element and increase both mid and low
            if(arr[mid] == 0){
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            //If mid is 1, increase mid only
            else if(arr[mid] == 1)
                mid++;
            //Else, if mid is 2, swap mid with high element, also decrement high
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};