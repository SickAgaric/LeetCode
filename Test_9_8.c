void reverseString(char *s, int sSize) {
    char *last = s + sSize - 1;
    while (s < last) {
        char tmp1 = *s;
        *s++ = *last;
        *last-- = tmp1;
    }
}

char *reverseWords(char *s) {
    char *result = s; 
    int count = 0; 
    while (*s) {
        if (*s != ' ') {
            count = count + 1; 
        } else if (count) {
            reverseString(s - count, count);
            count = 0; 
        }    
        s = s + 1; 
    }    
    reverseString(s - count, count);
    return result;
}

