/*int _climbStairs(int a,int n)
{
    if(a==n)
        return 1;
    if(a>n)
        return 0;
    
    return _climbStairs(a+1,n)+_climbStairs(a+2,n);
}

int _climbStairs(int n){
    
    int x = _climbStairs(0,n);
    return x;
}*/

int climbStairs(int n) {
    long int a = 1,b = 1;
    while(n--)
    {
        b = b + a;
        a = b - a;
    }
    return a;
}

int numJewelsInStones(char * J, char * S){
    int num = 0;
    char* _S = S;
    while(*J)
    {
        while(*_S)
        {
            if(*J == *_S)
                num++;
            _S++;
        }
        J++;
        _S = S;
    }
    
    return num;

}





int singleNumber(int* nums, int numsSize){
    int result = 0;
    
    for(int i = 0;i<numsSize;i++)
        result^=nums[i];//相同的位，与后为0，不同的为1
    return result;
}

