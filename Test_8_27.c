`bool isOneBitCharacter(int* bits, int bitsSize) 
{
	int i=0;
	if(bits[bitsSize-1] != 0)
		return 0;
	if(bitsSize == 1)
		return 1;

while(1)
{
    if(bits[i] == 1)
    {
        i+=2;
    }
    else
    {
        i++;
    }
    
    if(i==(bitsSize-1))
        return 1;
    
    if(i>(bitsSize-1))
        return 0;
}` 