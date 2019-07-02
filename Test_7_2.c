//66 加一
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;
    for(i;i >= 0;i--){
        if(digits[i] < 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0; 
    }
    int* new = (int*) malloc ((digitsSize + 1) * sizeof (int));
    new[0] = 1;
    for(i = 1;i < (digitsSize + 1);i++)
        new[i] = 0;
    *returnSize = digitsSize + 1;
    return new;
}


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *rev;
    int i;
    for(i=0; i<digitsSize && digits[i] == 9; i++) ;
    if(i < digitsSize){
        rev = (int*)malloc(digitsSize*sizeof(int));
        *returnSize = digitsSize;
        int n = 0;
        for(i=0; i<digitsSize; i++){
            if(digits[digitsSize-i-1] != 9) break;
            n++;
        }
        rev[digitsSize-n-1] = digits[digitsSize-n-1] + 1;
        for(i=0; i<digitsSize-n-1; i++){
            rev[i] = digits[i];
        }
        for(i=digitsSize-n; i<digitsSize; i++){
            rev[i] = 0;
        }
        return rev;
    }else{
        rev = (int*)malloc((digitsSize+1)*sizeof(int));
        *returnSize = digitsSize + 1;
        rev[0] = 1;
        for(i=1; i<(digitsSize+1); i++) rev[i] = 0;
    }
    return rev;     
}