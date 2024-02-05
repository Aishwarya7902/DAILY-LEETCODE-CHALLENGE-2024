PROBLEM :https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

VIDEO :


/*
  APPROACH 1
  */

//TC :O(n)
//SC: O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>mp;
        for(auto it:s){
            mp[it]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1)return i;
        }

        return -1;
    }
};
