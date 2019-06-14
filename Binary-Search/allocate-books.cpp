// Helper function to check if the number of students required overflows for a value

bool isPossible(vector<int> A, int mid, int B) {
    int studentsRequired = 1; 
    int curr_sum = 0; 

    for (int i = 0; i < A.size(); i++) { 
        if (A[i] > mid) 
            return false;
        if (curr_sum + A[i] > mid) {
            studentsRequired++;
            curr_sum = A[i];
            if (studentsRequired > B) 
                return false; 
        }
        else
            curr_sum += A[i]; 
    } 
    return true;
}
int Solution::books(vector<int> &A, int B) {

    // Corner case

    if (B > A.size()) {
        return -1;
    }

    long long sum = 0;

    // Binary Search from start to end(possible values)

    for (int i = 0; i < A.size(); i ++) {
        sum += A[i];
    }
    int start = 0;
    int end = sum;
    int result = INT_MAX; 
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(A, mid, B)) {
            result = min(result, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}
