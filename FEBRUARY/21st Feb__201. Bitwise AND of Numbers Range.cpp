PROBLEM :https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

VIDEO:

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
