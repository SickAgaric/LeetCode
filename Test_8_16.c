    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1=0,size2=0;
        ListNode *p=l1,*pre=l1,*q=l2,*qre=l2;
        // 得到两个链表长度
        while(p) {
            p=p->next;
            size1++;
        }
        while(q) {
            q=q->next;
            size2++;
        }
        p=l1,q=l2;
        int flag=0;
        int tmp;
        while(l1&&l2) {
            if(size1>size2) {
                tmp=l1->val;
                l1->val = (l1->val+l2->val+flag)%10;
                flag = (tmp+l2->val+flag)/10;        
            }
            else {
                tmp=l2->val;
                l2->val = (l1->val + l2->val + flag) % 10;
                flag = (l1->val+tmp+flag)/10;        
            }
            pre=l1;
            l1=l1->next;
            qre=l2;
            l2=l2->next;
        }
        // l2不为空，l1空
        while(!l1&&l2) {
            int tmp = l2->val;
            l2->val = (flag+l2->val)%10;
            flag = (flag+tmp)/10;        
            qre=l2;
            l2=l2->next;
        }

        // l1不为空，l2空
        while(!l2&&l1) {
            int tmp = l1->val;
            l1->val = (flag+l1->val)%10;
            flag = (flag+tmp)/10;        
            pre=l1;
            l1=l1->next;
        }
        if(flag) {
            if(size1>size2) {
                pre->next = new ListNode(flag);
                pre->next->next=NULL ;
                return p;
            } else {
                qre->next = new ListNode(flag);
                qre->next->next=NULL ;
                return q;
            }
        }
        if(size1>size2)
            return p;
        return q;
    }
	
	int rob(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    else
    {
  int *MAX=(int *)malloc(numsSize*sizeof(int));
 for(int i=0;i<numsSize;i++)
  {
      if(i==0)
          MAX[i]=nums[i];
      else
      {
          if(i==1)
          {
              if(nums[1]>nums[0])
                  MAX[1]=nums[1];
              else
                  MAX[1]=MAX[0];
          }
          else
          {
              int result=MAX[i-2]+nums[i];
              if (result>MAX[i-1])
              {
                  MAX[i]=result;
              }
              else
                  MAX[i]=MAX[i-1];
              
          }
      }
  }
        return MAX[numsSize-1];  
}
    }