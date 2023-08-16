class Solution {
public:
    ListNode* mergeTwoLists(ListNode* lista, ListNode* listb) {
        if (lista == nullptr)
        return listb;
        if (listb == nullptr)
            return lista;

        ListNode* mergedList = nullptr;
        if (lista->val <= listb->val) {
            mergedList = lista;
            mergedList->next = mergeTwoLists(lista->next, listb);
        } else {
            mergedList = listb;
            mergedList->next = mergeTwoLists(lista, listb->next);
        }

        return mergedList;
       
    }
};