//203 移除链表元素


ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}


struct ListNode* removeElements(struct ListNode* head, int val){ 
    struct ListNode *p=head,*s=NULL;
    int i=0; 
    if(head==NULL)
    { 
        return NULL;
    }
    if(head->next==NULL)
    { 
        if(head->val==val)
        {
            free(head);
            return NULL;
        } 
    } 
    while(head)
    { 
        if(head->val==val)
        {
            if(p==head||i==0)
            {
                p=p->next; 
            } 
            else
            {
                s->next=head->next;
                free(head);
                head=s; 
            } 
        }
        else{
            i++; 
            } 
        s=head; 
        head=head->next;
    }
    return p;
}


