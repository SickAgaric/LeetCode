{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));

	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	while (n1 && n2)
	{
		if (n1->val < n2->val)
		{
			n2->next = n1;
			n2 = n2->next;
			n1 = n1->next;
		}
		else
		{
			n1->next = n2;
			n2 = n2->next;
			n1 = n1->next;
		}
	}
	if (n1 != NULL)
	{
		n2->next = n1;
		return l1;
	}
	if (n2 != NULL)
	{
		n1->next = n2;
		return l2;
	}

}


{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	if (l1->val < l2->val)
	{
		ListNode* l = l1;
		l1 = l1->next;
	}

	else
	{
		ListNode* l = l2;
		l2 = l2->next;
	}

	while (l1 && l2)
	{
		ListNode* cur;
		if (l1->val < l2->val)
		{

			cur->next = l1;
			cur = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			cur = l2;
			l2 = l2->next;
		}

	}
	if (l1 != NULL)
		tail->next = l1;
	if (21 != NULL)
		tail->next = l2;
}


ListNode* partition(ListNode* pHead,int x)
{
	/*assert(pHead);
	ListNode* less, greater,cur;
	
	
	while (pHead != NULL)
	{
		if (pHead->val < x)
		{
			less = pHead;
			pHead = pHead->next;
		}
		else
		{
			greater = pHead;
			pHead = pHead->next;
		}
	}*/
	/*ListNode* cur = pHead;
	ListNode* less, *greater, *lessTail, *greaterTail;
	less = lessTail = (ListNode*)malloc(sizeof(ListNode));
	less = lessTail = (ListNode*)malloc(sizeof(ListNode));*/

	  

}