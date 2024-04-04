PROBLEM : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04
VIDEO : https://www.youtube.com/watch?v=uzP77oJVLos

/*
BRUTE FORCE (USING STACK)
TC:O(N)
SC:O(N)
*/

class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        stack<char>st;
        for(auto &ch:s){
           if(ch=='('){
            st.push(ch);
           }
           else if(ch==')') st.pop() ;

           result=max(result,int(st.size()));//st.size() returns size in datatype size_t...hence typeconversion needed
        }
        return result;
    }
};

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
