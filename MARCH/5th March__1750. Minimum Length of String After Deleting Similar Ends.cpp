PROBLEM :https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

VIDEO :https://www.youtube.com/watch?v=skEofEGj46Y
/*
Companies
1 year - 2 years
Goldman Sachs
Amazon
*/

/*
  TC:O(N)
  SC:O(1)

  */

class Solution {
public:
    int minimumLength(string s) {
        int  n=s.length();
        int i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<j && s[i]==ch)i++;

            while(j>=i && s[j]==ch)j--;

        }

        return j-i+1;
    }
};
