PROBLEM :https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

VIDEO:https://www.youtube.com/watch?v=3XYQLHSoew8

/*
Companies
6 months - 1 year
Google
2
1 year - 2 years
Apple
2
Amazon
2
Yahoo
2
*/


/*
  APPROACH 1
  TC:O(log(n))
  SC:
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount=0;
        while(left!=right){
            left= (left>>1);
            right= (right>>1);
            shiftCount++;
        }

     return (left<<shiftCount);
    }
};

/*

APPROACH 2
  */

class Solution {
public:
    // TC :O(log(n) base 2)
    int rangeBitwiseAnd(int left, int right) {
       while(right>left){

           right=(right&(right-1));  // n&(n-1)
       }
       return right;
    }
};
