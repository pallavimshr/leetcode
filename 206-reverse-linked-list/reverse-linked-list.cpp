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
    ListNode* reverseList(ListNode* head) {
        // Initially, there is no previous node
        ListNode* prev = nullptr;

        // Start from the first node
        ListNode* current = head;

        // Process each node until we reach the end
        while (current != nullptr) {

            // 1. Save the next node before changing the link
            ListNode* nextNode = current->next;

            // 2. Reverse the current node's pointer
            current->next = prev;

            // 3. Move prev to the current node
            prev = current;

            // 4. Move current to the saved next node
            current = nextNode;
        }

        // prev is now the new head of the reversed list
        return prev;
    }
};
