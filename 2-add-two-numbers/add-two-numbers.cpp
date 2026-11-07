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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node banaya.
        // Ye answer linked list ke starting point ki tarah kaam karega.
        ListNode dummy(0);

        // tail pointer result list ke last node ko track karega.
        ListNode* tail = &dummy;

        // Carry initially 0 hai.
        int carry = 0;

        // Jab tak dono lists mein nodes hain
        // ya carry bacha hua hai, loop chalao.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            // Current digits initially 0 rakhe.
            int sum = carry;

            // Agar l1 mein node available hai,
            // toh uski value sum mein add karo.
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Agar l2 mein node available hai,
            // toh uski value sum mein add karo.
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current result digit nikalo.
            int digit = sum % 10;

            // Next iteration ke liye carry nikalo.
            carry = sum / 10;

            // Result ka naya node banao.
            ListNode* newNode = new ListNode(digit);

            // Result list ke end mein naya node jodo.
            tail->next = newNode;

            // Tail ko naye last node par move karo.
            tail = tail->next;
        }

        // Dummy node ko skip karke actual answer return karo.
        return dummy.next;
    }
};
