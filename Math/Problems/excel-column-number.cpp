int Solution::titleToNumber(string A) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }
    int j = 0;
    int num = 0;

    // Equivalent to number system in base 26

    for (int i = A.size() - 1; i >= 0; i --) {
        int temp = A[i];
        num += pow(26, A.size() - 1 - i) * (temp - 64);
        
    }
    return num;
}
