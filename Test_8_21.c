char * defangIPaddr(char * address){
    char *ret = malloc(sizeof(char) * 22);
    char *r = ret;
    
    while (*address) {
        if (*address == '.') {
            *ret++ = '[';
            *ret++ = '.';
            *ret++ = ']';
            address++;
        } else {
            *ret++ = *address++;
        }
    }
    
    *ret = '\0';
    
    return r;
}
