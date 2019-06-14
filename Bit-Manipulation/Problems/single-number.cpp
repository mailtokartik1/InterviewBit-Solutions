int Solution::singleNumber(const vector<int> &A) {

    // The XOR of a number with itself is zero
    // However the XOR of a number with 0 is 0

    int num = 0;
    for (int i = 0; i < A.size(); i ++) {
        num = num ^ A[i];
    }
    return num;
}
