int Solution::pow(int A, int n, int d) {

    // Corner cases

    long long x = A;
    if (n == 0) {
        return 1 % d;
    }
    if (x == 0) {
        return 0;
    }
    if (d == 1) {
        return 0;
    }
    long long int ans = 1;

    // Separation of concerns based on whether the exponent is divisible by 2 or not

    bool sign;
    if (x < 0) {
        if (n % 2 == 1) {
            sign = false;
        } else {
            sign = true;
        }
    } else if (x >= 0) {
        sign = true;
    }
    x = abs(x);

    // Binary Exponentiation

    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * x) % d;
        }
        x = (x * x) % d;
        n = n / 2;
    }
    if (!sign) {
        ans = -1 * ans;
    }
    if (ans < 0) {
        while (ans < 0) {
            ans += d;
        }
    }
    return ans;
}
