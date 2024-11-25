/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1)
        return head;

    int count = 0;
    struct ListNode* current = head;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (count == k) {
        struct ListNode* prev = NULL;
        current = head;
        struct ListNode* next = NULL;
        for (int i = 0; i < k; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = reverseKGroup(current, k);
        return prev;
    }
    return head;
}