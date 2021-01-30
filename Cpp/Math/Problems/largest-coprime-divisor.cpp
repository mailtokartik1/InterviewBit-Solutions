// Helper function to get the gdc

int gcd (int m, int n) {
    if (m < n) {
        swap(m, n);
    }
    if (n == 0) {
        return m;
    } else {
        return gcd(n, m % n); 
    }
}
int Solution::cpFact(int A, int B) {

    // Remove all the common factors between A and Bs

    while (gcd(A, B) != 1) {
        A = A / gcd(A, B);
    }
    if (gcd(A, B) == 1) {
        return A;
    }
}
