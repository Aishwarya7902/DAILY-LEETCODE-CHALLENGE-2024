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


/*

SPACE OPTIMISATION
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    ListNode* ReverseLL(ListNode* node){
        if(!node || !node->next)return node;
        ListNode* temp=node->next;
        node->next=NULL;
        ListNode* ans=ReverseLL(temp);
        temp->next=node;
        return ans;


    }
    ListNode* findMid(ListNode* head,ListNode* prev){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        /*
        story
        ->find mid ✅
        ->reverse LL ✅
        ->check palindrome ✅
        */
     ListNode* mid=NULL;
     ListNode* prev=NULL;
     mid=findMid(head,prev); //step 1
     ListNode* tail=ReverseLL(mid); // step 2
     while(head && tail){ //step 3
        if(head->val!=tail->val)return false;
        head=head->next;
        tail=tail->next;
     }

     return true;

    }
};
