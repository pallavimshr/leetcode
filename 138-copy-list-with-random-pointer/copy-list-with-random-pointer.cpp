/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) {
            return nullptr;
        }

        // STEP 1: Har original node ke just baad
        // uski copied node insert karna.

        Node* current = head;

        while (current != nullptr) {

            // Current node ki value se copy create karo.
            Node* copy = new Node(current->val);

            // Copy ko current ke next node se connect karo.
            copy->next = current->next;

            // Original current node ka next ab copy hoga.
            current->next = copy;

            // Agle original node par jao.
            current = copy->next;
        }


        // STEP 2: Copied nodes ke random pointers connect karna.

        current = head;

        while (current != nullptr) {

            // Current ke just baad uski copy hai.
            Node* copy = current->next;

            // Agar original ka random nullptr hai,
            // toh copied random bhi nullptr hoga.
            if (current->random != nullptr) {

                // Original random node ke just baad
                // uski copied node present hai.
                copy->random = current->random->next;
            }

            // Agle original node par move karo.
            current = copy->next;
        }


        // STEP 3: Original aur copied lists ko separate karna.

        current = head;

        // Copied list ka head store kar lo.
        Node* copyHead = head->next;

        while (current != nullptr) {

            // Current original node ki copy.
            Node* copy = current->next;

            // Original list ko uske next original node se connect karo.
            current->next = copy->next;

            // Agar next original node exist karta hai,
            // toh copied node ko next copied node se connect karo.
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            // Agle original node par move karo.
            current = current->next;
        }

        // Copied linked list ka head return karo.
        return copyHead;
    }
};
