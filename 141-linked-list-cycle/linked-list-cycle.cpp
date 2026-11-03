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

        // Both pointers start from head
        ListNode* slow = head;
        ListNode* fast = head;

        // Fast must have a next node to move two steps
        while (fast != nullptr && fast->next != nullptr) {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // If both pointers meet, cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached NULL, no cycle
        return false;
    }
};
