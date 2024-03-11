PROBLEM : https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

VIDEO :https://www.youtube.com/watch?v=oGPfmp71Zm4

/*
  METHOD 1
  T.C : O(m+n)
  S.C : O(26) ~ O(1)
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int count[26]={0};
        //storing freq of each char of s
        for(auto &ch:s){
            count[ch-'a']++;
        }

        string result="";
       // which ever char of order are in s put in result
        for(auto &ch:order){
            while(count[ch-'a']--){
                result.push_back(ch);
            }
        }

        for(auto &ch:s){
            if(count[ch-'a']>0)result.push_back(ch);
        }
    
     return result;
    }
};
