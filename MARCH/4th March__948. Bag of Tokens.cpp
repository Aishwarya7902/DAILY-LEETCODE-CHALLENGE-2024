PROBLEM :https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04
VIDEO :https://www.youtube.com/watch?v=LCx1WzlYgvw

/*
Companies
1 year - 2 years
Bloomberg
3
Apple
2
Google
*/

/*
  GREEDY
  TC:O(nlogn)
  SC:O(1)
  */

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int maxScore=0;

        sort(begin(tokens),end(tokens));
        int i=0,j=n-1;

        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                maxScore=max(score,maxScore);
            }

            else if(score>=1){
                power+=tokens[j];
                score-=1;
                j--;
            }
            else{
                return maxScore;
            }
        }
         return maxScore;
    }
};
