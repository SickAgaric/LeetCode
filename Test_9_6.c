struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL)return NULL;
    int count=0;
    struct ListNode* tmp=head;
    struct ListNode* last;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    if(count==1 && n==1)return NULL;
    tmp=head;
    for(int i=1;i<count-n+1;i++){
        last=tmp;
        tmp=tmp->next;
    }
    if(tmp==head)
        return head->next;
    last->next=tmp->next;
    free(tmp);
    return head;
}