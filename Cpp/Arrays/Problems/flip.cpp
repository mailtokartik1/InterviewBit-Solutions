vector<int> Solution::flip(string A) {
    vector<int> B;

    // Corner case

    if (A.length() <= 0) {
        return B;
    }

    // Inialize values(LOTS OF THEM!!)

    int i = 0, j = i + 1, flag = 0, maxi = INT_MIN, curCount = 0, curL = i, L = -1, R = -1;

    // Count number of 1s and 0s

    for (j = 0; j < A.size(); j ++) {
        if (A[j] == '0') {
            curCount ++;
        } else if (A[j] == '1') {
            curCount --;
        }

        // Apply Kadane's Algorithm
        
        if (curCount > maxi && curCount > 0) {
            maxi = curCount;
            R = j;
            L = curL;
        }
        if (curCount < 0) {
            curCount = 0;
            curL = j + 1;
        }
        
    }
    if (L == -1 && R == -1) {
        return B;
    }
    else {
        B.push_back(L + 1);
        B.push_back(R + 1);
    }
    return B;
}
