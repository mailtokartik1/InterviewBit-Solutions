vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > B(A, vector<int>(A));

    // Corner case

    if (A <= 0) {
        return B;
    }
    int temp = 1;

    // I know variables are usually supposed to start with a lowercase letter, I know *sigh*

    // Keep 4 variables to mark the 4 corners of the traversal and dir for direction

    int T = 0, Be = A - 1, L = 0, R = A - 1, dir = 0;
    while (Be >= T && R >= L) {
        if (dir == 0) {
            for (int j = L; j <= R; j ++) {
                B[T][j] = temp;
                temp ++;
            }
            T ++;
            if (T <= Be) {
                dir ++;
            } else
                break;
        }
        if (dir == 1) {
            for (int i = T; i <= Be; i ++) {
                B[i][R] = temp;
                temp ++;
            }
            R --;
            if (L <= R) {
                dir ++;
            } else
                break;
        }
        if (dir == 2) {
            for (int j = R; j >= L; j --) {
                B[Be][j] = temp;
                temp ++;
            }
            Be --;
            if (T <= Be) {
                dir ++;
            } else
                break;
        }
        if (dir == 3) {
            for (int i = Be; i >= T; i --) {
                B[i][L] = temp;
                temp ++;
            }
            L ++;
            if (L <= R) {
                dir ++;
            } else
                break;
        }
        dir = 0;
    }
    return B;
}
