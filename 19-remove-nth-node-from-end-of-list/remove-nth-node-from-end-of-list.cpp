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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node before head
        ListNode dummy(0);
        dummy.next = head;

        // Both pointers start at dummy
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // STEP 1: Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // STEP 2: Move both pointers together
        // until fast reaches NULL
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // STEP 3: Remove the target node
        ListNode* nodeToDelete = slow->next;

        slow->next = nodeToDelete->next;

        delete nodeToDelete;

        // Return the updated head
        return dummy.next;
    }
};
