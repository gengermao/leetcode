int lengthOfLongestSubstring(char* s) {
    int alphabet[128], i, maxLength;
    char *p, *q;
    
    maxLength = 0;
    
    for(p = s; *p != '\0';p++){
        
        for(i = 0; i < 128; ++i)
            alphabet[i] = 0;
        
        for(q = p, i = 0; *q != '\0'; q++){
            if(!alphabet[*q]){
                ++alphabet[*q];
                ++i;
                if(i > maxLength)
                    maxLength = i;
            }else{
                break;
            }
                
        }        
    }
    return maxLength;
}
