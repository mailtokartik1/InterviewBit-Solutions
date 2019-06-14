int Solution::reverse(int A) {

    // Corner case

    if (A == 0) {
        return 0;
    }

    // Store the sign of the number and perform operations on it by making it positive

    vector<int> B;
    int C = A;
    A = abs(A);
    while (A >= 1) {
        B.push_back(A % 10);
        A = A / 10;
    }
    long long num = 0;
    for (int i = 0; i < B.size(); i ++) {
        num += B[i] * pow(10, B.size() - 1 - i);
    }
    if (num > INT_MAX) {
        return 0;
    }

    // Return the answer according to the sign

    if (C < 0) {
        return -1 * num;
    } else return num;
}
