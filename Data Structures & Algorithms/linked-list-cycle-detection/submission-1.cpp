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
    bool hasCycle(ListNode* head) {
        ListNode* it1 = head;
        ListNode* it2 = head;

        while(it2 != nullptr && it2 -> next != nullptr) {
            it1 = it1 -> next;
            it2 = it2 -> next -> next;

            if(it1 == it2) {
                return true;
            }
        }

        return false;
    }
};
