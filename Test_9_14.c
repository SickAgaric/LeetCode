char * convert(char * s, int numRows){
    int m=(numRows-1)*2;
    if(numRows==1)return s;
    int index[strlen(s)];
    char ans[strlen(s)+1];
    int n=0;
    for(int i=0;i<=m/2;i++){
        for(int j=0;j<strlen(s);j++){
            if(j%m==i||j%m==(m-i)){
                index[n]=j;n++;}
        }
    }
    for(int j=0;j<strlen(s);j++){
        ans[j]=s[index[j]];
        //printf("%c",ans[j]);
    }
    ans[strlen(s)]='\0';
    puts(ans);
    return ans;
}