PROBLEM :https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12

VIDEO: https://www.youtube.com/watch?v=5UWEVMg10rY
/*
Companies
6 months - 1 year
Amazon
2
josh technology
2
1 year - 2 years
Google
3
Uber
*/


/*
  //T.C : O(n^2)
//S.C : O(n) - We took a map
  */


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        unordered_map<int,ListNode*>mp;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[0]=dummy;

        while(head){
             prefixSum+=head->val;
             if(mp.find(prefixSum)!=mp.end()){
                ListNode* start=mp[prefixSum];
                ListNode* temp=start;

                int pSum=prefixSum;
                while(temp!=head){
                    temp=temp->next;
                    pSum+=temp->val;
                    if(temp!=head)
                     mp.erase(pSum);
                }
                start->next=temp->next;
             }
             else{
                mp[prefixSum]=head;
             }
             head=head->next;
        }
        return dummy->next;
    }
};
