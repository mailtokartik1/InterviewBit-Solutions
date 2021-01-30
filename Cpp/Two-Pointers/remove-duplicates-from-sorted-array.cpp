int Solution::removeDuplicates(vector<int> &A) {
    bool check = false;
    int start = 0;

    // Loop through the array and check adjacent elements

    for (int i = 0; i < A.size() - 1; i ++) {
        if (check) {
            if (A[i + 1] != A[i]) {
                A.erase(A.begin() + start, A.begin() + i);
                i = start;
                i --;
                check = false;
            }
        } else {
            if (A[i + 1] == A[i]) {
                //A.erase(A.begin() + i, A.begin() + i + 1);
                //i --;
                //cout << i;
                start = i;
                check = true;
            }
        }
    }
    if (check) {
        A.erase(A.begin() + start, A.end() - 1);
    }
    return A.size();
}

