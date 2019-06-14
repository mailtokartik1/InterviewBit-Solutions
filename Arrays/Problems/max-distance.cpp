int Solution::maximumGap(const vector<int> &A) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }

    // We make 2 max, min arrays for checking min value and max value in the array before and after the element respectively

    vector<int> leftMin(A);
    vector<int> rightMax(A);
    
    int mini = INT_MIN;
    int maxi = INT_MAX;

    leftMin[0] = A[0];
    for (int i = 1; i < A.size(); i ++) {
        leftMin[i] = min(A[i], leftMin[i - 1]);
    }
    rightMax[A.size() - 1] = A[A.size() - 1];
    for (int i = A.size() - 2; i >= 0; i --) {
        rightMax[i] = max(A[i], rightMax[i + 1]);
    }

    //Iterate over the array and find the maximum j - i

    int i = 0, j = 0, result = -1;
    while (j < A.size() && i < A.size()) {
        if (leftMin[i] <= rightMax[j]) {
            result = max(result, j - i);
            j ++;
        } else {
            i ++;
        }
    }
    return result;
}
