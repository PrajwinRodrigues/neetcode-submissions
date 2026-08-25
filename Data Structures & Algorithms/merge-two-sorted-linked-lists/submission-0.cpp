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
    ListNode *merege(ListNode *l1,ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1==NULL && l2==NULL) return NULL;
        ListNode *t1=l1,*t2=l2,*p,*start=NULL;
        while(t1!=NULL && t2!=NULL){
            if(start==NULL){
                if(t1->val<t2->val){
                    start=t1;
                    t1=t1->next;
                    p=start;
                }
                else{
                    start=t2;
                    t2=t2->next;
                    p=start;
                }
            }
            else{
                if(t1->val<t2->val){
                    p->next=t1;
                    p=t1;
                    t1=t1->next;
                }
                else{
                    p->next=t2;
                    p=t2;
                    t2=t2->next;
                }
            }
        }
        while(t1!=NULL){
            p->next=t1;
            p=t1;
            t1=t1->next;
        }
        while(t2!=NULL){
            p->next=t2;
            p=t2;
            t2=t2->next;
        }
        return start;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merege(list1,list2);
    }
};
