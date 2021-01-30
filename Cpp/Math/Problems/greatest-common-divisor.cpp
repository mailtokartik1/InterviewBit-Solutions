// Euclidean algorithm

int getGcd(int A, int B) {
    if (B == 0) {
        return A;
    } else return getGcd(B, A % B);
}
int Solution::gcd(int A, int B) {
    return getGcd(max(A, B), min(A, B));
}
