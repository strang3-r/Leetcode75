class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        if(head->next==NULL) return NULL;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
    }
};
