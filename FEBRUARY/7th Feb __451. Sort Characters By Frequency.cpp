PROBLEM :https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
VIDEO :

/*
  BRUTE FORCE
  TC: O(nlogn) ....coz of sorting
  SC: O(N)+ O(N) ....map and vector
*/

class Solution {
public:
    typedef pair<char,int>P;
   static bool cmp(P &a,P &b){
         return a.second > b.second;
    }
         
    
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto it:s){ //o(n)
            freq[it]++;
        }
    vector<P>vec;
    for(auto it:freq){
        vec.push_back(it);
    }

    sort(vec.begin(),vec.end(),cmp); //nlogn
    string result="";
    for(auto it:vec){
      result+=string(it.second,it.first);
    }
     return result;
 }

};
