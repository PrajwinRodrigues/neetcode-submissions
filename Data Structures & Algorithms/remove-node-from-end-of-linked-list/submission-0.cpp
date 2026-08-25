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
        int total=0;
        ListNode *temp=head,*prev;
        while(temp!=NULL){
            total+=1;
            temp=temp->next;
        }
        temp=head;
        int c=0;
        while(c!=total-n){
           c+=1;
           prev=temp;
           temp=temp->next;
        }
        if(temp==head && total==1) return NULL;
        if(temp==head) return temp->next;
        if(temp->next==NULL){
            prev->next=NULL;
            return head;
        }
        prev->next=temp->next;
        free(temp);
        return head;
    }
};
