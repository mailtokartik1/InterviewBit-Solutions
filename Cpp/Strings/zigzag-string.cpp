string Solution::convert(string A, int B) {

    // Corner case

    if (B >= A.size()) {
        return A;
    } else if (B == 1) {
        return A;
    }
    int temp = B;
    string C;
    int i;

    // Logic to get to the next position

    for (i = 0; i < temp; i ++) {
        for (int j = i; j < A.size(); j += 2 * ((B - 1) - (j % (B - 1)))) {
            C += A[j];
        }
    }
    return C;
}
