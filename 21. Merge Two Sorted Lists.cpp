class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        
        while(a && b){
            if(a->val < b->val) {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a) temp->next = a;
        if(b) temp->next = b;
        return dummy->next;
    }
};