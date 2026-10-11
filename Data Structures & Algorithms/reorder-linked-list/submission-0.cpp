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
    ListNode * reverse(ListNode *head){
        if(head==NULL) return NULL;
        ListNode *t=head,*p=head,*s=NULL;
        while(t!=NULL){
            p=t->next;
            t->next=s;
            s=t;
            t=p;
        }
        return s;
    }
    void reorderList(ListNode* head) {
        if(head->next==nullptr || head->next->next==nullptr) return ;
        ListNode *slow=head;
        ListNode *fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *l2=reverse(slow->next);
        slow->next=NULL;
        ListNode *l1=head;

        ListNode *temp1=l1,*temp2=l2;
        while(l2!=NULL){
            temp1=l1->next;
            temp2=l2->next;
            l1->next=l2;
            l2->next=temp1;
            l1=temp1;
            l2=temp2;
        }
    }
};
