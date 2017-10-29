/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    
    LNode *l3, *p, *q, *pnew, *temp;
    int carrybit;
    int sum;
    
    l3 = (LNode *)malloc(sizeof(LNode));
    l3->val = 0;
    l3->next = NULL;
    carrybit = 0; 
    temp = l3;
    
    for(p = l1,q = l2; p != NULL && q != NULL; p = p->next, q = q->next){
        
        sum = p->val + q->val + carrybit;
        
        if(sum >= 10){
            carrybit = 1;
            sum = sum - 10;
        }else
            carrybit = 0;
        
        temp->val = sum;
        temp->next = NULL;
        if(p->next != NULL && q->next != NULL){
            pnew = (LNode *)malloc(sizeof(LNode));
            pnew->next = NULL;
            temp->next = pnew;
            temp = pnew;     
        }
    }   
    
    if(p == NULL && q != NULL){
        for(; q != NULL; q = q->next)
        {
            sum = q->val + carrybit;
        
            if(sum >= 10){
                carrybit = 1;
                sum = sum - 10;
            }else
                carrybit = 0;
        
            pnew = (LNode *)malloc(sizeof(LNode));
            pnew->val = sum;
            pnew->next = NULL;
            temp->next = pnew;
            temp = pnew;       
        }
    }
    
    if(p != NULL && q == NULL){
        for(; p != NULL; p = p->next)
        {
            sum = p->val + carrybit;
        
            if(sum >= 10){
                carrybit = 1;
                sum = sum - 10;
            }else
                carrybit = 0;
        
            pnew = (LNode *)malloc(sizeof(LNode));
            pnew->val = sum;
            pnew->next = NULL;
            temp->next = pnew;
            temp = pnew;     
               
        }
    }
   
    if(p== NULL && q == NULL && carrybit){
        pnew = (LNode *)malloc(sizeof(LNode));
        pnew->val = carrybit;
        pnew->next = NULL;
        temp->next = pnew;
        temp = pnew;
    }
    return l3;        
}
