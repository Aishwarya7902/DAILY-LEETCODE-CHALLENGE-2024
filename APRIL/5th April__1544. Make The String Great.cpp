PROBLEM :https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

VIDEO :https://www.youtube.com/watch?v=J43ZIltH3AY

/*
  TC:O(N)
  SC:O(N)
  */

class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(s[i]);
                continue;
            }

            if(abs(ans.back()-s[i])==32)ans.pop_back();
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
