class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
ListNode* slow = head;
ListNode* fast = head;



if(head==NULL||head->next==NULL)return NULL;

while(fast&&fast->next){
        
fast = fast->next->next;
slow = slow->next;

if(fast==slow){
        slow = head;
        while(fast!=slow){
                if(fast==slow){
                        break;
                }
                else{
                        slow = slow->next;
                        fast = fast->next;
                }
        }
        return slow;
}
}

return NULL;
    }
};