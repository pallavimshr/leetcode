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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Create a dummy starting node
        ListNode dummy(0);

        // Current points to the last node of merged list
        ListNode* current = &dummy;

        // Continue while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {

                // Connect smaller node from list1
                current->next = list1;

                // Move list1 forward
                list1 = list1->next;
            }
            else {

                // Connect smaller node from list2
                current->next = list2;

                // Move list2 forward
                list2 = list2->next;
            }

            // Move current to the newly connected node
            current = current->next;
        }

        // Attach whichever list still has nodes
        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        // Return the actual head, skipping dummy
        return dummy.next;
    }
};
