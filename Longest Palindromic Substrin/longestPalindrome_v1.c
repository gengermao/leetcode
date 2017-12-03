char* longestPalindrome(char* s) {
    char c;
    int i, j;
    int tempBegin, begin, len, maxLen, isHavePal;
    char *temp;
    
    tempBegin = begin = len = isHavePal = 0;
    maxLen = 1;
    
    for(i = 0; s[i] != '\0'; i++){
        for(j = 0; j <= i; j++){
            if(s[i-j] == s[i+1+j]){
                tempBegin = i - j;
                len = 2 * j + 2;
                isHavePal = 1;
            }else
                isHavePal = 0;
            if(!isHavePal)
                break;
        }
        
        if(maxLen < len){
            begin = tempBegin;
            maxLen = len;
        }
    }
    for(i = 0; s[i] != '\0'; i++){
        for(j = 0; j <= i - 1 ; j++){
            if(s[i-1-j] == s[i+1+j]){
                tempBegin = i - 1 - j;
                len = 2 * j + 3;
                isHavePal = 1;
            }else 
                isHavePal = 0;
            if(!isHavePal)
                break;
        }
        
        if(maxLen < len){
            begin = tempBegin;
            maxLen = len;
        }
    }
    
    temp = (char *)malloc((maxLen + 1) * sizeof(char));
    for(i = 0; i < maxLen; i++)
        temp[i] = s[i + begin];
    temp[i] = '\0';
    
    return temp;
}
