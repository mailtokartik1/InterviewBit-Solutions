vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> C;

    // Corner case

    if (A.size() <= 1) {
        return C;
    }

    // Get 2 equations from sum of all numbers of A and sum of all numbers from 1 to N

    long long int S = (A.size() * (A.size() + 1)) / 2;
    long long int tot= 0;
    for (int i = 0; i < A.size(); i ++) {
        tot += A[i];
    }
    int diff = S - tot;
    long long int ST = 0, tT = 0;
    for (int i = 0; i < A.size(); i ++) {
        ST += (long long int)(i + 1) * (long long int)(i + 1);
    }
    for (int i = 0; i < A.size(); i ++) {
        tT += (long long int)(A[i]) * (long long int)(A[i]);
    }
    int sum = (ST - tT) / diff;
    int B = (sum + diff) / 2;
    int a = sum - B;
    C.push_back(a);
    C.push_back(B);
    return C;
}
