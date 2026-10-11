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
       ListNode *fast=head,*slow=head;
       int c=0;
       while(c!=n){
        fast=fast->next;
        c+=1;
       } 
       ListNode *prev=head;
       while(fast!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
       }
       if(slow==head){
        head=head->next;
        delete slow;
        return head;
       }
       prev->next=slow->next;
       delete slow;

       return head;
    }
};
