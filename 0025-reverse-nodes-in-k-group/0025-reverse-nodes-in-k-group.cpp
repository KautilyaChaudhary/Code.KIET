class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        for (int i = 0; i < n; i += k)
            if (i + k <= n)
                reverse(nums.begin() + i, nums.begin() + i + k);

        head = new ListNode(0);
        ListNode *temp = head;

        for (int i = 0; i < n; i++)
        {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }

        return head->next;
    }
};