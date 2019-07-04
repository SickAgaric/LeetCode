//加一
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i = digitsSize - 1;
	for (i; i >= 0; i--)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
	digits[i] = 0;
	}
	int* new = (int*)malloc((digitsSize + 1) * sizeof (int));
	new[0] = 1;
	for (i = 1; i < digitsSize + 1; i++)
		new[i] = 0;
	*returnSize = digitsSize+1;
	return new;

}
//移除元素
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (!head)
		return NULL;

	struct ListNode *p, *pre;

	p = head;
	pre = p;
	while (p)
	{
		if (p->val == val)
		{
			if (p == head)
			{
				head = head->next;
				p = head;

			}
			else{
				p = p->next;
				pre->next = p;
			}
		}
		else
		{
			pre = p;
			p = p->next;
		}
		

	}
	return head;

}

