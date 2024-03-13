PROBLEM :https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
VIDEO :


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
