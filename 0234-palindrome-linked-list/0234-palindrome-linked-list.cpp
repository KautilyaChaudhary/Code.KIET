class Solution {
    private:
    ListNode* getmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* getreverse(ListNode * head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * forw = NULL;

        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        } 

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }

        ListNode * middle = getmiddle(head);
        ListNode * temp = middle->next;

        middle->next = getreverse(temp);

        ListNode * head1 = head;
        ListNode * head2 = middle->next;

        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;    
    }
};