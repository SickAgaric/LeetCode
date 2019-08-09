bool wordPattern(char * pattern, char * str){
    char dict[128][128] = {0};
    char words[128];
    char wid = 0;
    
    char* tmp = NULL;
    int i = 0,j = 0;
    for(tmp = strtok(str," ");pattern[i]!='\0' && tmp!=NULL;i++,tmp = strtok(NULL," ")){
        char cur = pattern[i];
        if(dict[cur][0] == 0){
            strcpy(dict[cur],tmp);
            words[wid++] = cur;
        }else if(strcmp(dict[cur],tmp) != 0) return false;
        for(j = 0; j < wid;j++) if(cur != words[j] && strcmp(dict[words[j]],tmp) == 0) return false;
    }
    if(tmp != NULL || pattern[i]!='\0') return false;
    return true;
    
}