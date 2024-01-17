PROBLEM :https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17
VIDEO (MIK BHAIYA):


/*
  BRUTE FORCE (DID IT ON MY OWN)
  TC:O(N)
  SC:O(N)+O(N)
  */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       //take a freq map

       unordered_map<int,int>mp;
       for(int &num:arr){
           mp[num]++;
       }

       //take a set
       unordered_set<int>st;

       //traverse in map...if curr frequecny is not in set put it... and if it is already present ...it means  two values have the same number of occurrences.

       for(auto &it :mp){
           int freq=it.second;
           if(st.find(freq)!=st.end())return false;
           st.insert(freq);
       } 
       return true;
    }
};
