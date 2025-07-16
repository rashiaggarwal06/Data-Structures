class Solution {
public:
    string frequencySort(string s){
        //Create a map to store frequencies for every element of the string
        map<char, int> freq;
        for(char ch : s) 
            freq[ch]++;
        //Create a pair vector that is used to store integer, character of the frequency map we have created above
        vector<pair<int, char>> freqVector;
        for(auto& it : freq) 
            freqVector.push_back({it.second, it.first});
        //we now sort the freqVector in reverse order(highest frequency first)
        sort(freqVector.rbegin(), freqVector.rend());
        //create a string to return 
        string res = "";
        //Iterate over the freqVector to store chars in the resultant string res
        for(auto& it : freqVector)
            res += string(it.first, it.second);  //It takes string(count, character), means (3, e)=>eee, (1, t)=>t, (1, r)=>r
        return res;
    }
};
