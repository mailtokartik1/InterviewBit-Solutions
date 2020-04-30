#define MOD 1000003
long long int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return (fact(n - 1) * n) % MOD;
}
int Solution::findRank(string A) {
    
    // Store in an array

    bool alpha[52] = {0};
    for (int i = 0; i < A.size(); i ++) {
        if (islower(A[i])) {
            alpha[A[i] - 'a' + 26] = 1;
        } else {
            alpha[A[i] - 'A'] = 1;    
        }
    }

    // Traverse the string to find combinations

    long long int total = 0;
    for (int i = 0; i < A.size(); i ++) {
        int countLess = 0;
        long long localCount = 0;
        int size = islower(A[i]) ? A[i] - 'a' + 26 : A[i] - 'A';
        for (int j = 0; j < size; j ++) {
            countLess += alpha[j] ? 1 : 0;
        }
        if (islower(A[i])) {
            alpha[A[i] - 'a' + 26] = 0;
        } else {
            alpha[A[i] - 'A'] = 0;
        }
        localCount = (countLess * fact(A.size() - i - 1)) % MOD;
        total = total + localCount;
    }
    return (total + 1) % MOD;
}