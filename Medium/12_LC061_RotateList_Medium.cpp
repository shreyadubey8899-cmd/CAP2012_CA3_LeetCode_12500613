
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // If list is empty or has only one node
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Calculate length and find last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        // Reduce unnecessary rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Make circular linked list
        tail->next = head;

        // Find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;

        for (int i = 0; i < steps; i++) {
            newTail = newTail->next;
        }

        // Find new head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};
