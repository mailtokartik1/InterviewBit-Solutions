// We just shift the bits and use the XOR operator to reverse bits

int swapBits(unsigned int x, int i, int j) {
    int lo = ((x >> i) & 1);
    int hi = ((x >> j) & 1);
    if (lo ^ hi) {
        x ^= ((1U << i) | (1U << j));
    }
    return x;
}
unsigned int Solution::reverse(unsigned int x) {
    for (int i = 0; i < 16; i ++) {
        x = swapBits(x, i, 32 - i - 1);
    }
    return x;
}
