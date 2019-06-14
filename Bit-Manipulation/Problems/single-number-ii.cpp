int Solution::singleNumber(const vector<int> &A) {

    // We will have 3x + 1 bits in one position
    // we find the remainder on division by 3
    // and return the element

    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < A.size(); j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}