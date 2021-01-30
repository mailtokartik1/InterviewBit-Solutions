int Solution::removeDuplicates(vector<int> &A) {
    bool check = false;
    int start = 0;
    int count = 0;

    // Loop through the array and check adjacent elements
    // This time keep the pointer one step ahead the duplicate element

    for (int i = 0; i < A.size() - 1; i ++) {
        if (check) {
            if (A[i + 1] != A[i]) {
                if (count >= 2) {
                    A.erase(A.begin() + start + 1, A.begin() + i);
                    check = false;
                    i = start + 1;
                    i --;
                    count = 0;
                } else {
                    check = false;
                    count = 0;
                }
            } else {
                count ++;
            }
        } else {
            if (A[i] == A[i + 1]) {
                count = 2;
                check = true;
                start = i;
            }
        }
    }
    if (check) {
        if (count >= 2) {
            A.erase(A.begin() + start + 1, A.end() - 1);
        }
    }
    return A.size();
}
