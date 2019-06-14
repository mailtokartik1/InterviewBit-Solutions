int Solution::searchInsert(vector<int> &A, int B) {

    // Binary Search from start to end

    int start = 0, end = A.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            end = mid - 1;
        } else if (A[mid] < B) {
            start = mid + 1;
        }
    }
    return start;
}
