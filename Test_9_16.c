void CreateBrackets(char** retcha, char* partcha, int left, int right, int n, int *returnSize)
{
    if(left + right == n*2)
	{
		partcha[left+right] = '\0';
		retcha[*returnSize] = partcha;
		(*returnSize) ++;
		return;
	}else{
    if(left == right)
    {
        partcha[left + right] = '(';
		CreateBrackets(retcha, partcha, left + 1, right, n, returnSize);
    }else{
		if(left == n)
		{
			partcha[left + right ] = ')';
			CreateBrackets(retcha, partcha, left, right + 1, n, returnSize);
		}else{
			partcha[left + right] = '(';
			CreateBrackets(retcha, partcha, left + 1, right, n, returnSize);
			char* partcha1 = (char*)malloc(1000*sizeof(char));
			for(int k = 0; k < left+right; k++) partcha1[k] = partcha[k];
			partcha1[left + right] = ')';
			CreateBrackets(retcha, partcha1, left, right + 1, n, returnSize);
		}
	}
	}
}