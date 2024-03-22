PROBLEM :https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-22

VIDEO :

/*
   BRUTE FORCE (OWN)
   TC :O(n)
   SC:O(n)
   STORY❤️
   ->convert LL into string 
   -> check if given string is a palindrome
*/

class Solution {
public:
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        ListNode* temp=head;
        string s="";
        while(temp){
            s+=char(temp->val);
            temp=temp->next;
        }

        return isPalindrome(s);
    }
};
