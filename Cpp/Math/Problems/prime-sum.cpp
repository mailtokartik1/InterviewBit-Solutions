vector<int> Solution::primesum(int A) {
    vector<int> B;
    vector<bool> C(A, 1);
    C[0] = 0;
    C[1] = 0;

    // Loop from 0 through A - 1 to check for the existence of the numbers

    for (int i = 0; i < A; i ++) {
        if (C[i] == 1) {
            for (int j = 2; j * i < A; j ++) {
                if (C[i] == 1) {
                    C[i * j] = 0;
                }
            }   
        }
    }
    for (int i = 2; i <= floor(A/2); i ++) {
        if (C[i] == 1 && C[A - i] == 1) {
            B.push_back(i);
            B.push_back(A - i);
            break;
        }
    }
    return B;
}