/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while (ptr2->next != nullptr && ptr2->next->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2) {
                return true;
            }
        }
        return false;
    }
};
