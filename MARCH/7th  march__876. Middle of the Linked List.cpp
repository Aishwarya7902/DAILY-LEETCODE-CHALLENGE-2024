PROBLEM : https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
VIDEO :https://www.youtube.com/watch?v=I8h_hI_BF3Y

/*
Companies
0 - 6 months
Amazon
6
Apple
3
Bloomberg
3
Adobe
2
Google
2
6 months - 1 year
Uber
3
1 year - 2 years
Facebook
5
Oracle
3
Qualcomm
2
Walmart Labs
*/
/*
BRUTE FORCE (2 pass soultion)
TC:O(2N)
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

/*
OPTIMIZAION (2 pass soultion)

SLOW AND FAST POINTER
TC:O(N)
SC:O(1)
*/
class Solution {
public:
   // when fast reaches end then slow will definately will be at mid 
   //coz fast has 2x speed as compared to slow
    ListNode* middleNode(ListNode* head) {
      if(!head || !head->next)return head;
      ListNode* slow=head;
      ListNode* fast=head;

      while(fast && fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
    }
};


/*
APPROACH 2:
TC:O(M+N)
SC:O(1)
    */
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]==nums2[j])return nums1[i];

            else if(nums1[i]<nums2[j])i++;
            else j++;
        }
        return -1;
    }
};
