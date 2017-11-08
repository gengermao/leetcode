#define    LEN          (128)
#define    MAX(a, b)    ((a) > (b)) ? (a) : (b)

int lengthOfLongestSubstring(char* s) {
    int index[LEN] = {0};
    int max = 0;
    int i, j;
    
    for (i = 0, j = 0; s[j]; j++)
    {
        i = MAX(index[s[j]], i);
        max = MAX((j - i + 1), max);
        index[s[j]] = j + 1;
    }
    
    return max;
}
