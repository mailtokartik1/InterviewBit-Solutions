int Solution::search(const vector<int> &A, int B) {
    int start = 0;
    int end = A.size() - 1;
    int pivot;
    start = 0;
    end = A.size() - 1;

    // Binary Search based on different cases for a rotated matrix

    while (start <= end) {
        int mid = ((start + end) / 2) % A.size();
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] <= A[end]) {
            if (B >= A[mid] && B <= A[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else if (A[start] <= A[mid]) {
            if (B >= A[start] && B <= A[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}
