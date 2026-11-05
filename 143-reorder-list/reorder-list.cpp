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

        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // STEP 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Split the list into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        // STEP 3: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* current = second;

        while (current != nullptr) {

            ListNode* nextNode = current->next;

            current->next = prev;

            prev = current;
            current = nextNode;
        }

        // After reversing, prev is the new head
        second = prev;

        // STEP 4: Merge both halves alternately
        ListNode* first = head;

        while (second != nullptr) {

            // Save the next nodes
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Connect first node to second node
            first->next = second;

            // Connect second node to next first node
            second->next = temp1;

            // Move both pointers forward
            first = temp1;
            second = temp2;
        }
    }
};
