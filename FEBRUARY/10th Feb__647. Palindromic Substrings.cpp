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
TC:
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
