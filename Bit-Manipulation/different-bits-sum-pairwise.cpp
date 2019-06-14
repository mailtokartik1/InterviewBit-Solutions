int Solution::cntBits(vector<int> &A) {

    // Same concept as Hamming Distance problem

    long long countT = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 32; i ++) {
        for (int j = 0; j < A.size(); j ++) {
            if (((A[j] >> i) & 1U)) {
                count1 ++;
            }
        }
        countT += (count1 * (A.size() - count1) * 2);
        count1 = 0;
    }
    return (countT) % (int)(pow(10, 9) + 7);
}
