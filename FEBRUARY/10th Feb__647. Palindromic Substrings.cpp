PROBLEM :  https://leetcode.com/problems/palindromic-substrings/?envType=daily-question&envId=2024-02-10

VIDEO :

/*
  BRUTE FORCE (SOLVED ON MY OWN 😎)
  TC: O(N^3)
  SC: O(1)

  */

class Solution {
public:
     bool isPalindrome(int i,int j,string s){
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            string curr=" ";
            for(int j=i;j<n;j++){
               
                if(isPalindrome(i,j,s))cnt++;
            }
        }
        return cnt;
    }
};


/*
METHOD 2
USING RECURSION
TC: O(n^3)
SC:
  */

class Solution {
public:
     bool isPalindrome(int i,int j,string s){
        if(i>j)return true;

        if(s[i]==s[j])return isPalindrome(i+1,j-1,s);

        return false;
    }
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            string curr=" ";
            for(int j=i;j<n;j++){
               
                if(isPalindrome(i,j,s))cnt++;
            }
        }
        return cnt;
    }
};


/*
MEMOIZATION
TC:O(N^2)
SC:O(N^2)
  */

class Solution {
public:
     int t[1001][1001];
     bool isPalindrome(int i,int j,string s){
        if(i>j)return true;
        if(t[i][j]!=-1)return t[i][j]; // 0 is for false , 1 for true

        if(s[i]==s[j])return t[i][j]=isPalindrome(i+1,j-1,s);

        return t[i][j]=false;
    }
    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int cnt=0;
        int n=s.size();

        for(int i=0;i<n;i++){
           
            for(int j=i;j<n;j++){
               
                if(isPalindrome(i,j,s))cnt++;
            }
        }
        return cnt;
    }
};
