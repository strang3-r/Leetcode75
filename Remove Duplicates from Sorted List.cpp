class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
      
        ListNode* tmp = head;
        ListNode* curr = head->next;
       
        while(curr!=NULL) {
            
            if(tmp->val == curr->val) {
               
                curr=curr->next;
            }
           
            else {
                tmp->next = curr;
                tmp = curr;
                curr = tmp->next;
            }
        }
        tmp->next = NULL;
        return head;       
    }
};
