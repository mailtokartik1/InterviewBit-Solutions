// Helper function to check if a string is a palidrome

bool isPalindrome(int start, int end, string A) {

    while (start <= end) {
        if (A[start] != A[end]) {
            return false;
        }
        start ++;
        end --;
    }
    return true;
}
int Solution::solve(string A) {

    // Corner case

    if(A.size() <= 0) {
        return 0;
    }
    int compareIndex = A.size() - 1;
    int chars = 0;

    // Reach the non palindromic part of the string

    for (int i = compareIndex; i >= 0; i --) {
        if (isPalindrome(0, i, A)) {
            chars = A.size() - i - 1;
            break;
        }
    }
    return chars;
}
