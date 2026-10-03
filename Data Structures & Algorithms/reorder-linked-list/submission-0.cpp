/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* mid;
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        mid = slow->next;
        slow->next = nullptr;

        bool first = true;
        ListNode* prev = nullptr;
        ListNode* curr = mid;

        while(curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        ListNode* it1 = head;
        ListNode* it2 = prev;
        
        int flag = 0;
        ListNode dummy(0);
        ListNode* f = &dummy;

        while(it1 != nullptr && it2 != nullptr) {
            if(flag == 0) {
                f->next = it1;
                f = f->next;
                it1 = it1->next;
                flag = 1;
            }else {
                f->next = it2;
                f = f->next;
                it2 = it2->next;
                flag = 0;
            }
        }

        if(it1 != nullptr) {
            f->next = it1;
        }else {
            f->next = it2;
        }

    }
};
