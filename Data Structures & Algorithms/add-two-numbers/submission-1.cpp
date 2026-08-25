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
        ListNode *t1=l1,*t2=l2;
        int sum=0,carry=0;
        ListNode *ans=NULL,*temp;
        while(t1!=NULL || t2!=NULL){
            if(t1){ sum+=t1->val;
             t1=t1->next;}
            if(t2) {sum+=t2->val;
            t2=t2->next;}
            carry=sum/10;
            sum=sum%10;
            ListNode *p=new ListNode(sum);
            if(ans==NULL){
                ans=p;
                temp=p;
            }
            else{
                temp->next=p;
                temp=p;
            }
            sum=carry;
            carry=0;
        }
        if(sum!=0){
            temp->next=new ListNode(sum); 
        }
        return ans;
    }
};
