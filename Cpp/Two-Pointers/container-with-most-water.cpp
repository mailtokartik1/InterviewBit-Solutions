int Solution::maxArea(vector<int> &A) {

    // Corner case

    if (A.size() <= 1) {
        return 0;
    }
    int i = 0;
    int j = A.size() - 1;
    int maxi = INT_MIN;

    // Keep one pointer at the start and one at the end
    // That will give the maximum width of the area
    // Keep changing the pointers until the values are the same

    for (int i = 0; i < A.size(); i ++) {
        for (j = A.size() - 1; j > i; j --) {
            if (A[i] <= A[j]) {
                int area = A[i] * (j - i);
                if (area > maxi) {
                    maxi = area;
                }
                break;
            } else {
                int area = A[j] * (j - i);
                if (area > maxi) {
                    maxi = area;
                }
            }
        }
    }
    return maxi;
}
