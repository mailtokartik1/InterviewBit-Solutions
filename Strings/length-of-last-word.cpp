int Solution::lengthOfLastWord(const string A) {
    int count = 0;
    int i;

   // Handle space characters 

    for (i = A.size() - 1; i >= 0; i --) {
        if (A[i] == ' ') {
        } else {
            break;
        }
    }

    // Count the length of the last word from the end

    for (; i >= 0; i --) {
        if (A[i] == ' ') {
            return count;
        } else count ++;
    }
    return count;
}

