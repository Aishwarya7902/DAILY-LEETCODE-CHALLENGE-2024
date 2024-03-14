PROBLEM :https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
VIDEO :
/*
Companies
1 year - 2 years
Apple
2
Amazon
*/


/*
  BRUTE FORCE
  TC: o(n^2)
  SC: o(1)
*/

class Solution {
public:
   int findSum(int st,int end){
    int sum=0;
    for(int i=st;i<=end;i++){
        sum+=i;
    }
    return sum;
   }

class Solution {
public:
   int findSum(int st,int end){
    int sum=0;
    for(int i=st;i<=end;i++){
        sum+=i;
    }
    return sum;
   }
    int pivotInteger(int n) {
       /*
       story
       -> try out every x from 1 to n-1
       ->if(findSum(1,x)==findSum(x,n))return x;
       ->if no such x exits...return -1

       */

       for(int  x=1;x<=n;x++){
        if(findSum(1,x)==findSum(x,n))return x;
       } 

       return -1;
    }
};
    int pivotInteger(int n) {
       for(int  x=1;x<=n;x++){
        if(findSum(1,x)==findSum(x,n))return x;
       } 

       return -1;
    }
};


/*
APPROACH 2
USING PREFIX SUM
TC:O(N)
SC:O(N)
*/

class Solution {
public:
   
    int pivotInteger(int n) {
      vector<int>prefixSum(n+1,0);
      int sum=0;
      for(int i=1;i<=n;i++){
        sum+=i;
        prefixSum[i]=sum;
      }

       for(int  x=1;x<=n;x++){
        if(prefixSum[x]==((prefixSum[n]-prefixSum[x])+x))return x;
       } 

       return -1;
    }
};


/*
APPROACH 3
USING MATHS
TC:O(N)
SC:O(1)
  */

class Solution {
public:
   
    int pivotInteger(int n) {
       int totalSum=(n*(n+1))/2; //formula for sum of first n natural numbers
       for(int x=1;x<=n;x++){
        int sumOneToX=(x*(x+1))/2;
        int sumXToN=totalSum-sumOneToX+x;
        if(sumOneToX==sumXToN)return x;
       }
       return -1;
    }
};
