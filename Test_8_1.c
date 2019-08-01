struct ListNode* swapPairs(struct ListNode* head) { int list_len = 0; int i = 1;
struct ListNode* cur = head; if(head == NULL || head->next == NULL) return head; while(cur != NULL){ cur = cur->next; list_len++;
} cur = head; struct ListNode *arry_list[list_len + 1];

while(i <= list_len  && cur != NULL){
    if(cur->next == NULL && list_len % 2 != 0){
        arry_list[list_len] = cur;
        arry_list[list_len - 1]->next = cur;
        break;
    }
    if(i % 2 == 0){
        arry_list[i - 1] = cur; 
        cur = cur->next;
        arry_list[i - 1]->next = arry_list[i];   
        if(i >= 3)
            arry_list[i - 2]->next = arry_list[i - 1];
    }else{
        arry_list[i + 1] = cur;
        cur = cur->next;
    }
    i++;   
}
arry_list[list_len]->next = NULL;
return arry_list[1];
}