/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LNode;
typedef struct ListNode* pstLNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    pstLNode p, q, temp;
    int carry;
    
    carry = 0;
    
    for(p = l1,q = l2; p != NULL && q != NULL; p = p->next, q = q->next)
    {
        p->val = p->val + q->val + carry;
        carry = p->val / 10;
        p->val = p->val % 10;
        temp = p;
    }
    
    if(p == NULL && q != NULL){
        temp->next = q;
        p = q;
        for(; p != NULL; p = p->next)
        {
            p->val = p->val + carry;
            carry = p->val / 10;
            p->val = p->val % 10;
            temp = p;
        }
    }
    else if(p != NULL && q == NULL){
        for(; p != NULL; p = p->next)
        {
            p->val = p->val + carry;
            carry = p->val / 10;
            p->val = p->val % 10;
            temp = p;
        }
    }
    if(carry){
        p = (LNode *)malloc(sizeof(LNode));
        p->val = carry;
        p->next = NULL;
        temp->next = p;
    }
    
    return l1;
}
