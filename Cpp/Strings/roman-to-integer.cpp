// Helper function to return the value associated with a Roman character

int val(char i) {
        if (i == 'M') {
            return 1000;
        } else if (i == 'D') {
            return 500;
        } else if (i == 'C') {
            return 100;
        } else if (i == 'L') {
            return 50;
        } else if (i == 'X') {
            return 10;
        } else if (i == 'V') {
            return 5;
        } else if (i == 'I') {
            return 1;
        }
}
int Solution::romanToInt(string A) {
    int count = 0;

    // Loop through the string from the end
    // If a character with more value is encountered
    // Add the subtracted value of the 2 to the count

    for (int i = A.size() - 1; i >= 0; i --) {
        int cur = val(A[i]);
        int pre;
        count += cur;
        if (i != 0) {
            pre = val(A[i - 1]);
            if (pre < cur) {
                count -= pre;
                i --;
            }
        }
    }
    return count;
}
