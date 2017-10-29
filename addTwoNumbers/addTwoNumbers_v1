/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LNode;

unsigned long power(int x,int n)  
{  
   unsigned long a=1;  
   int i;  
   for(i=1;i<=n;i++)  
   a*=x;  
   return a;      
}  

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int i;
    unsigned long integer1;
    LNode *l3, *p;
    
    l3 = (LNode *)malloc(sizeof(LNode));
    l3->val = 0;
    l3->next = NULL;
   
    integer1 = 0;
    
    for(p = l1,i = 0; p != NULL; p = p->next,i++){
        integer1 += (p->val) * power(10,i);
    } 
    
    for(p = l2,i = 0; p != NULL; p = p->next,i++){
        integer1 += (p->val) * power(10,i);
    }
   
    l3->val = integer1;
    l3->next = NULL;
    
    
    LNode *q,*pnew;
    q = l3;
    
    while(integer1)
    {
        q->val = integer1 % 10;
        q->next = NULL;
        if(integer1 >=10)
        {
            pnew = (LNode *)malloc(sizeof(LNode));
            pnew->next = NULL;
            q->next = pnew;
            q = pnew;
        }
        integer1 = integer1/10;
    }
    return l3;
}
