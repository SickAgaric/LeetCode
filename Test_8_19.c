bool isAnagram(char *s, char *t)
{
	int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++)	x[s[i] - 'a']++;	
	for (i = 0; t[i] != '\0'; i++)	y[t[i] - 'a']++;	
	for (i = 0; i < 26; i++)							//比较两字符表是否相同
		if (x[i] != y[i])	return false;
	return true;										//种类、个数均相同
}