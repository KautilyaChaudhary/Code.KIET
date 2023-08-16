class Solution {
public:
    ListNode* middleNode(ListNode* h) {
        ListNode *stack[100];
        int cnt = 0;
        while(h){
            stack[cnt++] = h;
            h = h->next;
        }
        return stack[cnt / 2];
    }
};