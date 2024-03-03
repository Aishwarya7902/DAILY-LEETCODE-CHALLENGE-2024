PROBLEM :https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

VIDEO : https://www.youtube.com/watch?v=ZQizovB_UdI

Problem Name : Remove Nth Node From End of List 
/*
Companies
0 - 6 months
Facebook
16
Amazon
9
Microsoft
5
Apple
5
Google
3
Adobe
3
Oracle
3
Nvidia
2
6 months - 1 year
Yahoo
2
1 year - 2 years
Bloomberg
4
American Express
3
Dell
3
eBay
2
ServiceNow
2
Uber
2
VMware
2
Nagarro
2
Intel
2
*/

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

/*
ONE PASS SOULTION
TC:O(N)
SC:O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode* temp=head;
        
            for(int i=1;i<=n;i++){
                temp=temp->next;
            }
        

        if(temp==NULL){ //it means n==L so we have to delete head
         ListNode* result=head->next;
         delete(head);
         return result;
        }

        ListNode* prev=head;
        while(temp!=NULL && temp->next!=NULL){
            prev=prev->next;
            temp=temp->next;
        }

        ListNode* delNode=prev->next;
        prev->next=prev->next->next;
        delete(delNode);
      
        return head;
    }
};
