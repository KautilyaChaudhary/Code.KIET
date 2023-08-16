class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* curr=head;
    ListNode* prevNode=NULL;
    ListNode* nextptr;
    while(curr!=NULL){
      nextptr=curr->next;
      curr->next=prevNode;
      prevNode=curr;
      curr=nextptr;

    }
    return prevNode;
    }
};