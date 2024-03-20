PROBLEM :https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

VIDEO:

/*
  BRUTE FORCE (OWN)
  TC:O(M+N)
  SC:O(1)
  */

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        /*
         story:-
         -> find a ✅
         ->find prev of a✅
         ->find b✅
         ->find tail of 2nd list (tail2) ✅

         -> prev->next=head2✅
         ->tail2->next=b->next✅
         ->b->next=NULL✅
         ->return head1;✅
         */
        // step 1,2,3 of story
        ListNode* tempA=list1; //a
        ListNode* prev=list1;  //prev
        ListNode* tempB=list1; //b

        while(a--){
            prev=tempA;
            tempA=tempA->next;
        }

        while(b--){
            
            tempB=tempB->next;
        }

        // 4th point of story
        ListNode* tail2=list2; 

        while(tail2->next){
            tail2=tail2->next;
        }

        // step 5,6,7,8 of story

          prev->next=list2;
          tail2->next=tempB->next;
          tempB->next=NULL;
          return list1;



    }
};
