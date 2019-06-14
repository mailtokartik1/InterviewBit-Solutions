string Solution::addBinary(string A, string B) {
    string temp;

    // Append zeroes at the end of the shorter string to make both string lengths equal

    if (A.length() != B.length()) {
        int mini = min(A.length(), B.length());
        if (mini == A.length()) {
            for (int i = 0; i < B.length() - A.length(); i ++) {
                temp += '0';
            }
            A = temp + A;
        } else if (mini == B.length()) {
            for (int i = 0; i < A.length() - B.length(); i ++) {
                temp += '0';
            }
            B = temp + B;
        }
    }
    int C = 0;
    temp.clear();

    // Ordinary division using sum and carry

    for (int i = A.size() - 1; i >= 0; i --) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int sum = a + b + C;
        int add = sum % 2;
        C = sum / 2;
        temp += add + '0';
    }
    if (C) {
        temp += '1';
    }
    reverse(temp.begin(), temp.end());
    return temp;
}