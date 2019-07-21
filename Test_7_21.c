/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
Node* CreatNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    
    newNode->next = NULL;
    newNode->random = NULL;
    
    return newNode;
    
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        
        while(cur)
        {
            Node* next = cur->next;
            Node* copynode = CreatNode(cur->val);
            
            cur->next = copynode;
            copynode->next = next;
            
            cur = next;
        }
        //制造 拆解
        cur = head;
        while(cur)
        {
            Node* copynode = cur->next;
            
            if(cur->random)
                copynode->random = cur->random->next;
            
            cur = cur->next->next;
        }
        
        Node* copyHead = CreatNode(0);
        Node* rear = copyHead;
        cur = head;
        while(cur)
        {
           Node* copynode = cur->next;
           Node* next = cur->next->next;
            
           cur->next = next;
            
           rear->next = copynode;
           rear = copynode;
           
           cur = next; 
        }
        
        Node* List = copyHead->next;
        free(copyHead);
        return List;
    }
    
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
     
    ListNode* f = head;
    ListNode* s = head;
    
    while(f && f->next)
    {
        f = f->next->next;
        s = s->next;
        
        if(f==s)
            return true;
    }
    return false;
    
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
ListNode* hasCycle(struct ListNode *head) {
     
    ListNode* f = head;
    ListNode* s = head;
    
    while(f && f->next)
    {
        f = f->next->next;
        s = s->next;
        
        if(f==s)
            return s;
    }
    return NULL;
    
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* M = hasCycle(head);
    
    if(M==NULL)
        return NULL;
    while(M!=head)
    {
        M = M->next;
        head = head->next;
    }
    return M;
    
}