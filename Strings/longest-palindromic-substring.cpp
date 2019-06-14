// Helper function to check if a string is a palindrome

bool isPalindrome(int start, int end, string A) {
    while (start <= end) {
        if (A[start] != A[end]) {
            return 0;
        }
        start ++;
        end --;
    }
    return 1;
}
string Solution::longestPalindrome(string A) {

    // Corner case

    if (A.size() <= 0) {
        return string();
    }
    string B;
    int startIndex = -1;
    int endIndex = -1;
    int max = INT_MIN;

    // Run 2 loops and check for the longest palindromic substring

    for (int i = 0; i < A.size(); i ++) {
        for (int j = A.size() - 1; j >= i; j --) {
            if (j - i + 1 > max) {
                if (isPalindrome(i, j, A)) {
                    if (j - i + 1 > max) {
                        startIndex = i;
                        endIndex = j;
                        max = j - i + 1;
                        break;
                    }
                }
            } else break;
        }
    }
    return A.substr(startIndex, endIndex - startIndex + 1);
}
