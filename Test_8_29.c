int uniqueMorseRepresentations(char ** words, int wordsSize){
    char m[][5]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char s[wordsSize+1][50];
    int num=wordsSize,i,j;
    for (i=0;i<wordsSize;i++)
    {    
        s[i][0]='\0';
        for (j=0;j<strlen(words[i]);j++)
            strcat(s[i],m[words[i][j]-97]);
    }    
    for (i=0;i<wordsSize;i++) 
        for (j=i+1;j<wordsSize;j++)
        {
            if (strcmp(s[i],s[j])==0) 
            {
                num--;
                break;
            }
        }
    return num;
}