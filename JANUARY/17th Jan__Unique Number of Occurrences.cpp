PROBLEM :https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17
VIDEO (MIK BHAIYA): https://www.youtube.com/watch?v=b2_rw2NZkr8


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


/*
  OPTIMISATION
  TC:O(nlogn)
  SC:o(1)
  */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //if u look at the contraints which is
        //-1000 <= arr[i] <= 1000 so Making benefit of constraints

        vector<int>vec(2001,0);
        for(int &x:arr){
            vec[x+1000]++;
        }

        sort(begin(vec),end(vec));
        for(int i=1;i<2001;i++){
            if(vec[i]!=0 && vec[i]==vec[i-1])return false;
        }

    return true;
    }
};
