class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> address;

        while(head != NULL) {
            for (int i = 0; i < address.size(); i++) {
                if (address[i] == head) {
                    return true;
                }
            }
            address.push_back(head);
            head = head->next;
        }
        return false;
    }
};