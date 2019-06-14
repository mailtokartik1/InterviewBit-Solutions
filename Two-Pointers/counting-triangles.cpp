int Solution::nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    if (A.size() < 3) {
        return 0;
    }
    int i = 0, j;
    int k;
    int ans = 0;

    // A triangle is formed when the sum of 2 sides is greater than the 3rd side
    // It would not be wise choice to start one pointer at the end because the sum goes monotonically
    // So we start the pointers at the start

    for (i = 0; i < A.size() - 2; i ++) {
        k = i + 2;
        j = i + 1;
        for(int j = i + 1; j < A.size(); j++) {
            for(; (k < A.size()) && (A[i] + A[j] > A[k]); k++);
            ans = ans + (k - 1 - j);
            if(ans >= pow(10, 9) + 7) ans = ans % (int)(pow(10, 9) + 7);
        }
    }
    return ans;
}
