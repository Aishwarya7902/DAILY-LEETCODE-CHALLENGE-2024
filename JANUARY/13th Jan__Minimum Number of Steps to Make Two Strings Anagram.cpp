PROBLEM : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13

VIDEO : (MIK BHAIYA)

  /*

  BRUTE FORCE (DONE BY SELF)
  TC:O(N)
  SC:O(N)
ALGO:
    1.Count the frequency of characters of each string.
    2.Loop over all characters if the frequency of a character in t is less than the frequency 
      of the same character in s then add the difference between the frequencies to the answer.

*/


  class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freqS(26);
        vector<int>freqT(26);
        for(char &ch:s){
            freqS[ch-'a']++;
        }
        for(char &ch:t){
            freqT[ch-'a']++;
        }

        int result=0;
        for(int i=0;i<26;i++){
            if(freqS[i]!=0 && freqS[i]>=freqT[i])
             result+=freqS[i]-freqT[i];
        }
        return result;
    }
};
