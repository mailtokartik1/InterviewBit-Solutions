// A & A - 1 unsets the lowest set bit
// so we just count until A == 0

int Solution::numSetBits(unsigned int A) { 
    int tot = 0;
    while (A != 0) {
        A = A & (A - 1);
        tot ++;
    }
    return tot;
}
