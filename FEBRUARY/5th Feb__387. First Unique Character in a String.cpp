PROBLEM :https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

VIDEO : https://www.youtube.com/watch?v=vqLiP9cdDLA


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


/*
SPACE OPTIMIZATION
  */

//TC :O(n)
//SC: O(1).....since it contains only a fixed size vector of size 26(only smallcase english alphabet)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>mp(26);
        for(char ch:s){
            mp[ch-'a']++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']==1)return i;
        }

        return -1;
    }
};

