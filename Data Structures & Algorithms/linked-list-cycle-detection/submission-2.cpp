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
    bool hasCycle(ListNode* head) {
        if(head==NULL) return 0;
        if(head->next==NULL) return 0;
        ListNode *slow=head,*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL && slow!=fast){
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow==fast;
    }
};
