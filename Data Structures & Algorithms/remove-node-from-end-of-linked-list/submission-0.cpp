class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* curr = head;

        while(curr != nullptr) {
            total++;
            curr = curr->next;
        }

        int target = total - n;

        curr = head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        int i = 0;

        while(curr != nullptr) {
            ListNode* next = curr->next;

            if(i == target) {
                prev->next = next;
                curr->next = nullptr;
                break;
            }

            prev = curr;
            curr = next;
            i++;
        }

        return dummy.next;
    }
};