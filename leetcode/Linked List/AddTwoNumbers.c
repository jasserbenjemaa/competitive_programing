/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* creatNode(int val){
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = creatNode(0);
    struct ListNode* current = head;
    int carry=0;
    while(l1!=NULL || l2!=NULL){
        int val1=l1==NULL?0:l1->val;
        int val2=l2==NULL?0:l2->val;
        int sum =val1+val2+carry;
        carry=sum/10;

        struct ListNode* node =creatNode(sum%10);
        current->next=node;
        current=node;
        
        if(l1!=NULL)l1=l1->next;
        if(l2!=NULL)l2=l2->next;
        
    }
    if(carry){
        struct ListNode* node =creatNode(1);
        current->next=node;
    }
return head->next;
        
}