/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* tail=head;
    tail->next=NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes
    tail->next = (list1 != NULL) ? list1 : list2;
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode* head = lists[0];
    for (int i = 1; i < listsSize; i++) {
        head = mergeLists(head, lists[i]);
    }
    return head;
}
