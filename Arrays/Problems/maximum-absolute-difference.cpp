int Solution::maxArr(vector<int> &A) {

    // Solution is an extension of the manhattan distance problem

    vector<int> plus = A;
    vector<int> minus = A;
    if (A.size() == 1) {
        return 0;
    }

    // Set array values for A[i] + i

    for (int i = 0; i < plus.size(); i ++) {
        plus[i] = plus[i] + i;
    }

    // Set array values for A[i] - i

    for (int i = 0; i < minus.size(); i ++) {
        minus[i] = minus[i] - i;
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    return max(plus[plus.size() - 1] - plus[0], minus[minus.size() - 1] - minus[0]);
}
