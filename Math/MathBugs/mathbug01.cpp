// Return 1 if A is prime, else 0

int Solution::isPrime(int A) {
    int upperLimit = (int)(sqrt(A));
    if (A == 1) {
        return 0;
    } else if (A <= 0) {
        return 0;
    } else if (A == 2 || A == 3) {
        return 1;
    }
    for (int i = 2; i <= upperLimit; i++) {
        if (i < A && A % i == 0) return 0;
    }
    return 1;
}
