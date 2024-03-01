PROBLEM:https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
VIDEO: https://www.youtube.com/watch?v=IRO_4X0csoc





/*
  LEARNING
  The binary representation of an odd number contains '1' in the least significant place.
  */

/*
  TC:O(n)
  SC:O(N)
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string result=string(n,'0');
        int i=0;
        for(char &ch:s){
            if(ch=='1'){
                if(result[n-1]=='1'){//The binary representation of an odd number contains '1' in the least significant place.
                   result[i]='1';
                   i++;
                }
                else{
                    result[n-1]='1';
                }
            }
        }
        return result;
    }
};


/*
APPROACH 2
TC: O(N)
S:O(N)
  */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        string result=string(n,'0');
        int j=0;
        //The binary representation of an odd number contains  one '1' in the least significant place and rest '1' in the most significant place.
        int count_1=count(s.begin(),s.end(),'1');
        while(count_1>1){
            result[j]='1';
            j++;
            count_1--;
        }

        result[n-1]='1';
        return result;
    }
};
