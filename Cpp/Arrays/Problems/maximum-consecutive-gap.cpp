int Solution::maximumGap(const vector<int> &A) {
    if (A.size() < 2) {
        return 0;
    }

    // check max and min for the bucket distribution

    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
        if (A[i] < mini) {
            mini = A[i];
        }
    }
    if (maxi == mini) {
        return 0;
    }

    // calculate the gap

    int gap = (maxi - mini - 1) / (A.size() - 1) + 1;
    
    vector<int> maxBucket(A.size() - 1, INT_MIN);
    vector<int> minBucket(A.size() - 1, INT_MAX);
    
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] != maxi && A[i] != mini) {
            int multip = (A[i] - mini) / gap;
            if (A[i] > maxBucket[multip]) {
                maxBucket[multip] = A[i];
            }
            if (A[i] < minBucket[multip]) {
                minBucket[multip] = A[i];
            }
        }
    }
    int maxim = INT_MIN;
    int previous = mini;
    for (int i = 0; i < A.size() - 1; i ++) {
        if (minBucket[i] == INT_MAX && maxBucket[i] == INT_MIN)
            continue;
        if (minBucket[i] - previous > maxim) {
            maxim = minBucket[i] - previous;
        }
        previous = maxBucket[i];
    }
    return max(maxim, maxi - previous);
}

