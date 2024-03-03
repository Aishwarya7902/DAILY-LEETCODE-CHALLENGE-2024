PROBLEM :https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

VIDEO : https://www.youtube.com/watch?v=ZQizovB_UdI

/*
  brute force (2 pass solution)
  tc:o(n) 
  sc:o(1)
  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L=findLength(head);
        int travel_from_front=L-n;
        // corner case 1 (n>L) ....but as given in ques ..this will not happen
        if(L==n){ //corner case 2
            ListNode* temp=head->next;
            delete(head);
            return temp;
        }
        ListNode* temp=head;
        ListNode* prev=head;
        while(travel_from_front--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;
    }
};
