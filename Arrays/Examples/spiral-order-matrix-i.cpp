vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> B;

    // Corner cases

    if (A.size() == 0) {
        return B;
    }
    if (A[0].size() == 0) {
        return B;
    }
    int t = 0, r = A[0].size() - 1, l = 0, b = A.size() - 1;
    int dir;

    // Keep 4 variables to mark the 4 corners of the traversal and dir for direction

    while (t <= b && l <= r) {
        dir = 0;
        if (dir == 0) {
            for (int i = l; i <= r; i ++) {
                B.push_back(A[t][i]);
            }
            t ++;
            if (t <= b) {
                dir ++;
            }
        }
        if (dir == 1) {
            for (int i = t; i <= b; i ++) {
                B.push_back(A[i][r]);
            }
            r --;
            if (l <= r) {
                dir ++;
            }
        }
        if (dir == 2) {
            for (int i = r; i >= l; i --) {
                B.push_back(A[b][i]);
            }
            b --;
            if (t <= b) {
                dir ++;
            }
        }
        if (dir == 3) {
            for (int i = b; i >= t; i --) {
                B.push_back(A[i][l]);
            }
            l ++;
            if (l <= r) {
                dir ++;
            }
        }
    }
    return B;
}
