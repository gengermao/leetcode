/***
  **we assume the nenegative integers are not palindrome numbers
***/
int reverse(int x) {
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
            return 0;
        result = newResult;
        x = x / 10;
    }

    return result;
}

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    if(x == reverse(x))
        return true;
    return false;
}
