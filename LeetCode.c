int romanToInt(char * s)
{
	int result = 0;
	int n = strlen(s);

	for (int i = 0; i < n; i++)
	{
		switch (s[i])
		{
		case'I':
			if (i < n - 1 && s[i + 1] == 'V')
			{
				result += 4;
				i++;
			}
			else if (i < n - 1 && s[i + 1] == 'X')
			{
				result += 9;
				i++;
			}
			else
				result++;
			break;
		case'V':
			result += 5;
			break;
		case'X':
			if (i < n - 1 && s[i + 1] == 'L')
			{
				result += 40;
				i++;
			}
			else if (i < n - 1 && s[i + 1] == 'C')
			{
				result += 10;
				i++;
			}
			else
				result += 10;
			break;
		case'L':
			result += 50;
			break;
		case'C':
			if (i < n - 1 && s[i + 1] == 'D')
			{
				result += 400;
				i++;
			}
			else if (i < n - 1 && s[i + 1] == 'M')
			{
				result += 900;
				i++;
			}
			else
				result += 100;
			break;
		case'D':
			result += 500;
			break;
		case'M':
			result += 1000;
			break;
		}
	}
	return result;
}
//两数之和 题号：1
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	assert(nums);
	int len = strlen(nums);
	int count = 0;
	int* returnSize = (int*)malloc(3*sizeof(int));
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; i < len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				returnSize[count] = i;
				returnSize[count+1] = j;
				count++;
				return returnSize;
			}
		}
	}
	return returnSize;

}
int* twoSum(int* nums, int numsSize, int target, int * returnSize)
{
	int * a = (int *)malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				a[0] = i; 
				a[1] = j;
				returnSize[0] = 2;
				return a;
			}
		}
	}
	returnSize[0] = 0;
	return 0;
}

//合并两个有序链表 21
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

