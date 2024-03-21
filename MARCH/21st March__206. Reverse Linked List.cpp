PROBLEM :https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21

VIDEO : https://www.youtube.com/watch?v=RreHsOfi14w

Problem Name : Reverse Linked List

Company Tags  : Google, Amazon, D.E. Shaw , Microsoft

/*
  BRUTE FORCE (OWN)
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* temp=head->next;
        head->next=NULL;
        ListNode* ans=reverseList(temp); //recursion will do rest 
        // result will be  5->4->3->2 (eg 1)

        // now just put head in the end.. 5->4->3->2->1

        temp->next=head;
        return ans;


    }
};
