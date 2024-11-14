/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int countNodes(struct ListNode* head){
    int i=0;
    while(head!=NULL){
        head=head->next;
        i++;
    }
    return i;
 }

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* current=head;
    struct ListNode* before=head;
    if(head==NULL)return head;
    k=k%countNodes(head);
    for(int i=0;i<k;i++){
    while(current->next!=NULL){
        before=current;
        current=current->next;
    }
    current->next=head;
    before->next=NULL;
    head=current;
    }
    return head;
}