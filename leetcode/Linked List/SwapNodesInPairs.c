/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void swap(struct ListNode* n1,struct ListNode* n2){
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(n1==NULL||n2==NULL)return;
    temp->val=n1->val;
    n1->val=n2->val;
    n2->val=temp->val;
 }
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* n1=head;
    struct ListNode* n2=head==NULL?NULL:head->next;
    while(n1!=NULL&&n2!=NULL){
        swap(n1,n2);
        n1=n2->next;
        n2=n1==NULL?NULL:n1->next;
    }
    return head;
}