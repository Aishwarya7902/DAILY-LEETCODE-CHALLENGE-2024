PROBLEM :https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

VIDEO :

/*

Companies
0 - 6 months
Amazon
5
Adobe
3
Google
2
6 months - 1 year
Apple
2
Microsoft
2
Bloomberg
2
Goldman Sachs
2
Uber
2
1 year - 2 years
Oracle
4
Spotify
4
Yandex
2
Cisco
2
SAP
2
Yahoo
*/

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
