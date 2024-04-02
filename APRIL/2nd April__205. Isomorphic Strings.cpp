PROBLEM :https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02

VIDEO : https://www.youtube.com/watch?v=2ISNCDJEgqQ
Company Tags  : LinkedIn

/*

  BRUTE FORCE 
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])return false;
                else{
                     i++;
                     continue;
                }
            }
            else if(st.find(t[i])!=st.end())return false;
            
            mp[s[i]]=t[i];
            st.insert(t[i]);
            i++;
        }

        return true;
    }
};

/*
TC:O(N)
SC:O(N)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

        for(int i=0;i<n;i++){
            char ch1=s[i];
            char ch2=t[i];

            if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2 || mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1)return false;
            

            mp1[ch1]=ch2;
            mp2[ch2]=ch1;
        }
   
        return true;
    }
};
