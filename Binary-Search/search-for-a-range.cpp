// Helper function to implement Binary Search

int findIndex(const vector<int> &A, int B, bool check) {
    int result = -1;
    int start = 0, end = A.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == B) {
            result = mid;
            if (check) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if (A[mid] > B) {
            end = mid - 1;
        } else if (A[mid] < B) {
            start = mid + 1;
        } 
    }
    return result;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {

    // Corner case

    vector<int> C;
    if (A.size() <= 0) {
        return C;
    }

    // Boolean value indicates lower or upper bound index

    C.push_back(findIndex(A, B, 1));
    C.push_back(findIndex(A, B, 0));
    return C;
}

