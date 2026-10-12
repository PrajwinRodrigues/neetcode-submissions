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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *start=NULL;
        ListNode *temp=NULL;
        int c=0,v;
        int s=0;
        ListNode *temp1=l1,*temp2=l2;
        while(temp1!=NULL && temp2!=NULL){
            s=c;
            s+=temp1->val;
            s+=temp2->val;
            v=s%10;
            c=s/10;
            ListNode * t=new ListNode(v);
            if(start==NULL){
                start=t;
                temp=t;
            }
            else{
                temp->next=t;
                temp=t;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=NULL){
            s=c;
            s+=temp1->val;
            v=s%10;
            c=s/10;
            ListNode *t=new ListNode(v);
            temp->next=t;
            temp=t;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            s=c;
            s+=temp2->val;
            v=s%10;
            c=s/10;
            ListNode *t=new ListNode(v);
            temp->next=t;
            temp=t;
            temp2=temp2->next;
        }

        if(c!=0){
            ListNode *t=new ListNode(c);
            temp->next=t;
            temp=t;
        }

        return start;
    }
};
