class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA=headA, *tempB=headB;
        int a=0,b=0,d;
        while(tempA) {a++; tempA=tempA->next;}
        while(tempB){b++; tempB=tempB->next;}
        d=abs(a-b);
        if(a>b) while(d--) headA=headA->next;
        else while(d--) headB=headB->next;
        while(headA && headB)
            if(headA==headB) return headA;
            else{
                headA=headA->next;
                headB=headB->next;
            }
        return nullptr;
    }
};