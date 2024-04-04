PROBLEM : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04
VIDEO :

/*

  SELF  (ACCEPTED)
  TC:O(N)
  SC:O(1)
*/
class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int cnt=0;
        for(auto &ch:s){
           if(ch=='('){
            cnt++;
            result=max(result,cnt);
           }
           if(ch==')')cnt--;
        }
        return result;
    }
};
