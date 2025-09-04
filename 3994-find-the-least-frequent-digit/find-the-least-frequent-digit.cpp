class Solution {
public:
    int getLeastFrequentDigit(int n) {
        //Convert number into string
        string s = to_string(n);
        //Create a unordered_map first to count frequency
        unordered_map<char, int> freq;
        for(char x : s)
            freq[x]++;
        //Create 2 variables to set minimum frequency and its key, If 2 or more keys has same frequency, we will pick the least key among them 
        int min_f = INT_MAX;
        char min_dig = '9' + 1;
        //Iterate over the frequency map
        for(auto it : freq){
            //Check if value has minimum digit, so make minimum frequency as it.second. Also, if both it.second and minimum frequency are same, then check for it.first if it is smaller than minimum digit or not, and its value accordingly
            if((it.second < min_f) || (it.second == min_f && it.first < min_dig)){
                min_f = it.second;
                min_dig =  it.first;
            }
        }
        //Return the key which occurs least number of time also has least value if 2 keys occurs same number of time, convert character to integer
        return min_dig - '0';
    }
};