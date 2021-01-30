int Solution::isPrime(int A) {
    if (A <= 1) {
        return 0;
    } else if (A == 2 || A == 3) {
        return 1;
    } else {
        for (int i = 2; i <= (int)(A/2); i ++) {
            if (A % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}