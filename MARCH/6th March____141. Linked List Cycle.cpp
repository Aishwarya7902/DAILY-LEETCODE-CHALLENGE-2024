PROBLEM :https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

VIDEO :

/*
  BRUTE FORCE :
  TC:O(N)
  SC:O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return false;

        unordered_map<ListNode*,bool>vis;
        // vis[head]=true;
        ListNode * temp=head;
        while(temp){
             if(vis[temp])return true;;
             vis[temp]=true;
             temp=temp->next;
        }

        return false;
    }
};
