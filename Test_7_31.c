
//283  移动零
void Swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize){
    
    //int* front = nums;
    //int* rear = nums;
    
    /*while(*rear!='\0'||*rear==0)
    {
        printf("a");
        if(*front==0 && *rear==0)
        {
            rear+=1;
        }
        printf("a");
        Swap(front,rear);
        front+=1;
        rear+=1;
        /*while(front != rear)
        {
            Swap(front,rear);
            front+=1;
            rear+=1;
        }}*/
        
 
    
    int countzero = 0;
    //将所有不为0的数字，覆盖到numsSize-countzero处的下标
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i]!=0)
            nums[countzero++] = nums[i];
    }
    
    //将countzero后的数组全部初始化为0，因为上一层循环，已经保存了所有不为0的数在countzero之前
    for(int i = countzero;i<numsSize;i++)
    {
        nums[i] = 0;
    }

}

//169 求众数


int majorityElement(int* nums, int numsSize){
    //计数法
    int count = 0;
    int mode = nums[0];
    for(int i =0;i<numsSize;i++)
    {

        if(mode==nums[i])
            count++;
        
        else
            count--;
        
        if(count==0)
            mode = nums[i+1];
    }
    
    return mode;

}

//69 x的平方根


int mySqrt(int x){
    long long sqrt = 1;
    
    while((sqrt*sqrt)<=x)
        sqrt+=1;
    
    return sqrt-1;

}

//344 翻转字符串
void Swap(char* a,char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize){
    
    int halfSize = sSize/2;
    int rear = sSize-1;
    
    for(int i = 0;i<halfSize;i++)
    {
        Swap(&s[i],&s[rear]);
        rear-=1;
    }

}

//234 回文链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode List;
struct ListNode* reverseList(struct ListNode* head)
{
    List* cur = head;
    List* _head = NULL;
    
    while(cur)
    {
        List* _next = cur->next;
        cur->next = _head;
        _head = cur;
        cur = _next;
    }
    return _head;
}

bool isPalindrome(struct ListNode* head){
    
    List* cur = head;
    int size = 0;
    while(cur)
    {
        cur = cur->next;
        size++;
    }
    
    int mid = size/2;
    
    cur = head;
    
    while(mid--)
        cur = cur->next;
    List* head1 = head;
    List* head2 = reverseList(cur);
    
    mid = size/2;
    
    while(mid--)
    {
        if(head1->val!=head2->val)
            return false;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;

}

//1021 删除最外层括号


char * removeOuterParentheses(char * S){
    /*int len = 0;
    int n = 0;
    int size = sizeof(char)/sizeof(S[0]);
    
    char* newstr = (char*)malloc(sizeof(char)*size);
    
    while(*S)
    {
    char* _S = S+1;
    while(*S++)
    {
        if(*S == '(')
            n+=1;
        else if(*S == ')')
            n-=1;
        
        if(n==0)
            break;
        
        len++;
    }
    for(int i = 0;i<len-2;i++)
    {
        newstr[i] = *_S;
        *_S++;
    }
    
    S = S+1;
    
    
    }
    return newstr;*/
    int sum = 0;
    int j = 0;
    
    int len = strlen(S);
    
    for(int i = 0;i<len;i++)
    {
        if(S[i]=='(')
            sum+=1;
        else
            sum-=1;
        
        if(S[i]=='('&&sum>1)
        {
            S[j] = '(';
            j++;

        }
        else if(S[i]==')'&&sum>0)
        {
            S[j] = ')';
            j++;
        }
        
    }
    S[j] = '\0';
    return S;
}


