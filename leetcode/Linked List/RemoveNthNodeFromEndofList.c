/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int countNodes(struct ListNode* head){
    int i=1;
    while(head!=NULL){
        head=head->next;
        i++;
    }
    return i;
 }
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* current = head;
    struct ListNode* before;
    int x=countNodes(head)-n;
    int i=1;
    while(current!=NULL && i!=x){
        before=current;
        current=current->next;
        i++;
    }
    if(current==NULL) return head;
    if(i==1) return head->next;
    before->next=current->next;
    
    
    return head;
}