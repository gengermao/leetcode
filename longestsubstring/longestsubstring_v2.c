int lengthOfLongestSubstring(char* s) {
    int i, c, LSubstring_start, maxSubLen;
    int alphabet[128] = {0};

    maxSubLen = LSubstring_start = 0;
    
    for(i = 0; c = s[i]; i++){
        if(alphabet[c] > LSubstring_start)           //判断当前重复的字符是否在上一个重复区间内，如果不是就计算长度
            LSubstring_start = alphabet[c];
        if((i - LSubstring_start + 1) > maxSubLen)
            maxSubLen = i - LSubstring_start + 1;
        alphabet[c] = i + 1;
    }
    return maxSubLen;
}
