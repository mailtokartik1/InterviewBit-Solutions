int Solution::Mod(int A, int B, int C) {

    // Corner case

    if (B == 0) {
        return 1 % C;
    } else if (A == 0) {
        return 0;
    }
    long long int x;

    // Use binary exponentiation
    // Also check for overflow cases

    if (B % 2 == 1) {
        x = (long long)((A % C) * (long long)(Mod(A, B - 1, C) % C)) % C;
    } else {
        x = (Mod(A, B / 2, C));
        x = x * x % C;
    }
    while (x < 0) {
        x += C;
    }
    return x;
}
