vector<int> Solution::allFactors(int A) {
    vector<int> B;

    // corner case

    if (A <= 0) {
        return B;
    }
    else if (A == 1) {
        B.push_back(1);
        return B;
    }

    // Iterate through 1 to sqrt(i)

    for (int i = 1; i <= (int)sqrt(A); i ++) {
        if (A % i == 0) {
            if (i == A / i) {
                B.push_back(i);
            } else {
                B.push_back(i);
                B.push_back(A/i);
            }
        }
    }
    sort(B.begin(), B.end());
    return B;
}
