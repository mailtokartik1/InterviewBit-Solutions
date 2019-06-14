int Solution::divide(int A, int B) {
    int sign = 1;

    // Use A and B as long long ints

    long long int q = 0, tmp = 0, ANew = A, BNew = B;

    // store the sign of the result

    if (ANew * BNew < 0) sign = -1;

    // Corner case

    if ((ANew == INT_MIN && BNew == -1) || BNew == 0) return INT_MAX;

    // Change A and B to positive values

    ANew = abs(ANew);
    BNew = abs(BNew);

    // Find the first bit for which B << i is less than A

    for (int i = 31; i >= 0; i--) { 
        if (tmp + (BNew << i) <= ANew) { 
            tmp += BNew << i; 
            q |= 1LL << i; 
        }    
    }
    return (int)(sign * q);
}