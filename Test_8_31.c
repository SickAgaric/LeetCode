bool detectCapitalUse(char* word) {
    int up = 0,low = 0;
    for(int i = 0;i < strlen(word);i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
            up++;
        if(word[i] >= 'a' && word[i] <= 'z')
            low++;
    }
    if(up == strlen(word) || low == strlen(word))
        return true;
    if(up == 1 && word[0] >= 'A' && word[0] <= 'Z')
        return true;
    return false;
}