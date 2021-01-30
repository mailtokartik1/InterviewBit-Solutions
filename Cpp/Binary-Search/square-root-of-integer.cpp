int Solution::sqrt(int A) {

    // Corner case

    if (A == 1) {
        return 1;
    }

    // Binary search from start to end(possible values of square roor)

    int start = 1, end = A / 2;
    int result;
    while (start <= end) {
        long long mid =  start + (end - start) / 2;
        if (mid * mid < A) {
            result = mid;
            start = mid + 1;
        } else if (mid * mid > A) {
            end = mid - 1;
        } else if (mid * mid == A) {
            return mid;
        }
    }
    return result;
}
