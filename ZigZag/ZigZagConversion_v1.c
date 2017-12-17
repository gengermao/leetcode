/*
we can group the string by the this form
------------------------->
A           | I
B        H  | J
C     G     | K      ....
D  F        | L  ...
E           | M

*/        

char* convert(char* s, int numRows) {
    int i, j, k, strLen, count;
    char *temp;
    
    count = 0;
    strLen = strlen(s);
    temp = (char *)malloc((strLen + 1) * sizeof(char));
    
    if (numRows == 1)
        return s;
    
    for(i = 0; i < numRows; i++)
    {
        for(j = i; j < strLen && s[j] != '\0'; j += (2 * numRows - 2))
        {
            temp[count++] = s[j];
            
            k = j + 2*(numRows - 1) -2*(j%(2*numRows-2));
            if(i > 0 && i < numRows -1 && k < strLen && s[k] != '\0')
                temp[count++] = s[k];
        }
    }
    
    temp[count] = '\0';
    
    return temp;
}
