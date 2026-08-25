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
    ListNode * sortl(ListNode *l1,ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *t1=l1,*t2=l2,*start=NULL,*temp;
        while(t1!=NULL && t2!=NULL){
            if(start==NULL){
                if(t1->val<t2->val){
                    start=t1;
                    t1=t1->next;
                    temp=start;
                }
                else{
                    start=t2;
                    t2=t2->next;
                    temp=start;
                }
            }
            else if(t1->val<t2->val){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        while(t1!=NULL){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        while(t2!=NULL){
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
        return start;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *start=NULL;
        for(auto it:lists){
            start=sortl(it,start);
        }
        return start;
    }
};
