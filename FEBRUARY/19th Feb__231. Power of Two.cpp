PROBLEM : https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

VIDEO : 

/*
Companies
0 - 6 months
Amazon
5
Adobe
3
Bloomberg
3
6 months - 1 year
Snapchat
2
1 year - 2 years
Apple
8
Google
3
General Motors
3
Uber
2
Qualcomm
2
JPMorgan
2

*/


/*
  BRUTE FORCE
  TC : O(N)
  SC : O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        while(n>1){
            cout<<n<<endl;
            if(n%2!=0)return false;
            n/=2;
        }
        return n==1;
    }
};


/*

METHOD 2
BIT MAGIC
TC : O(1)
SC : O(1)
  */

class Solution {
public:

 // the bit of n-1 will be all set expect
    // places which n has set for all n which is a power of 2

    /*
    eg 4= 100
       3= 011
    and when we take and then it will be zero
     (100) && (011) is 0
     hence n which was 4 is a power of 2
     */

    bool isPowerOfTwo(int n) {   
    if(n<=0)return false;
    return (n &(n-1))==0;
    }
};

/*

APPROACH 3
BUILT IN FUNCTION
  TC: logn base 2
  SC: O(1)
  */

class Solution {
public:
    bool isPowerOfTwo(int n) {   
    if(n<=0)return false;
    int count=__builtin_popcount(n);//this built in function return number of set bit in n
    //if a no is a power of 2 then set bit will always be 1
     return count==1;
    }
};

/*
METHOD 4
  TC:O(1)
  SC:O(1)
  */
  class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int curr = pow(2,30);
        return curr%n==0;
    }
};
