class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* it1 = list1;
        ListNode* it2 = list2;

        while(it1 != nullptr && it2 != nullptr) {

            if(it1->val < it2->val) {
                tail->next = it1;
                it1 = it1->next;
            } else {
                tail->next = it2;
                it2 = it2->next;
            }

            tail = tail->next;
        }

        if(it1 != nullptr) {
            tail->next = it1;
        } else {
            tail->next = it2;
        }

        return dummy.next;
    }
};