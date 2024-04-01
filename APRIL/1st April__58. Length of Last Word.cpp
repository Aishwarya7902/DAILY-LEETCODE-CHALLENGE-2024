PROBLEM :https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01
VIDEO :

/*
  BRUTE FORCE
  TC:O(N)
  SC:O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();

        int i=n-1;
        while(i>=0 && s[i]== ' ')i--;
        int cnt=0;
        while(i>=0 && s[i]!= ' '){
          cnt++;
          i--;
        }
     return cnt;
    }
};

