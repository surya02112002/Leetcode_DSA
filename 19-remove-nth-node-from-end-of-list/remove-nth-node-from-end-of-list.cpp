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
        ListNode* current = head;
        int length = 0;

        // Count the length of the linked list
        while (current != nullptr) {
            current = current->next;
            length++;
        }

        // If the length is equal to n, remove the head node
        if (length == n) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        current = head;  // Reset to the head
        ListNode* dummy = new ListNode(0);  // Create a dummy node
        ListNode* temp = dummy;

        // Traverse to the node before the one to be deleted
        int steps = length - n;
        for (int i = 0; i < steps; i++) {
            temp->next = current;
            temp = temp->next;
            current = current->next;
        }

        ListNode* nextNode = current->next;  // Save the next node
        delete current;  // Delete the node to be removed
        temp->next = nextNode;  // Link the previous node to the next node
        return dummy->next;
    }
};
