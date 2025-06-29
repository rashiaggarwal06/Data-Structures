class Solution {
public:
    int firstUniqChar(string s){
        unordered_map<char, int> mp; //To store the character, index mapping
        queue<int> q; //To store unique values only
        //Iterate over the whole string
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++; //Increase frequency
            if (mp[s[i]] == 1) {
                q.push(i); //First time seeing the character, store index
            }
            //Pop those characters from the queue which are having duplicates in the given string or those have frequency more than 1 in map
            while(q.size() > 0 && mp[s[q.front()]] > 1)
                q.pop();
        }
        //If queue is empty it means we have no element unique return -1, else return the index of the found element
        return q.empty() ? -1 : q.front(); 
    }
};