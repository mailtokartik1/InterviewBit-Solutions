int Solution::hammingDistance(const vector<int> &A) {

    // The trick is imagine if all the elements were either 0 or 1
    // then the value required will be 2 * (number of 1s) * (number of 0s)
    // We imagine each bit of the number and perform operations on them

    long long tot = 0;
    for (int i = 0; i < 32; i ++) {
        int count = 0;
        for (int j = 0; j < A.size(); j ++) {
            if (A[j] & 1 << i) {
                count ++;
            }
        }
        tot += (2 * count * (A.size() - count)) % 1000000007;
    }
    return tot % 1000000007;
}
