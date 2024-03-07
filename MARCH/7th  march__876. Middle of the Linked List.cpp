PROBLEM : https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
VIDEO :
/*
BRUTE FORCE
TC:O(N)
SC:O(1)
*/
class Solution {
public:
    int findLength(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {

        //edge cases
        if(!head || !head->next)return head;
        /*
        STORY->CODE
        1.find lenght of ll=n
        2. return n/2 th node
        */
        int n=findLength(head);
        ListNode* temp=head;
        n/=2;
        while(n--){
            temp=temp->next;
        }
        return temp;
    }
};
