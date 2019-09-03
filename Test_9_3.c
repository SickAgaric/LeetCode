const char* chars[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
const int charslen[8] = { 3,3,3,3,3,4,3,4 };
void per(char* arr, int size, char* stack, int top, char** res, int* ptr)
{
	if (size == 1)
	{
		for (int i = 0; i < charslen[arr[0] - '2']; ++i)
		{
			stack[top] = chars[arr[0] - '2'][i];
			for (int j = 0; j <= top; ++j)
			{
				res[*ptr][j] = stack[j];
			}
			++(*ptr);
		}
	}
	else
	{
		for (int i = 0; i < charslen[arr[0] - '2']; ++i)
		{
			stack[top] = chars[arr[0] - '2'][i];
			per(arr + 1, size - 1, stack, top + 1, res, ptr);
		}
	}
}
char** letterCombinations(char* digits, int* returnSize) 
{
	if (digits == NULL || digits[0] == '\0')
	{
		*returnSize = 0;
		return NULL;
	}
	int size = 1;
	int len = strlen(digits);
	for (int i = 0; i < len; ++i)
	{
		size *= charslen[digits[i] - '2'];
	}
	char** res = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; ++i)
	{
		res[i] = (char*)malloc(sizeof(char) * (len + 1));
		res[i][len] = '\0';
	}
	*returnSize = size;
	int ptr = 0;
	char stack[32];
	per(digits, len, stack, 0, res, &ptr);
	return res;
}

