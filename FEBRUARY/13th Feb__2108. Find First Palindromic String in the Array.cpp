PROBLEM : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

VIDEO :https://www.youtube.com/watch?v=JPB_lLGSgnc

/*
  BRUTE FORCE (SOLVED ON MY OWN)
  TC: O(M*N) 
      m is the size of longest string and n is size of words
  SC: 
*/


class Solution {
public:
    bool isPalindrome(string &str){
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){ 
            if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
};


/*
METHOD 2 
REVERSE METHOD
  */

class Solution {
public:
    bool isPalindrome(string &str){
        
      string temp=str;
      reverse(temp.begin(),temp.end());
      return str==temp;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){ 
            if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
};


/*

METHOD 3
  */
class Solution {
public:
    bool isPalindrome(string &str){
        
      return str==(string(rbegin(str),rend(str)));
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){ 
            if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
};


/*
METHOD 4:
*/

class Solution {
public:
    bool isPalindrome(string &str){
        int n=str.size();
        if(equal(str.begin(),str.begin()+n/2,str.rbegin()))return true;

        return false;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){ 
            if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
};
