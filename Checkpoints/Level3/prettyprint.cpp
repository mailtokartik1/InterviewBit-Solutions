vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>> res(2 * A - 1, vector<int>(2 * A - 1));
    int top = 0, bottom = res.size() - 1, left = 0, right = res[0].size() - 1;

    // Proceed in the same way as spiral matrix

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i ++) {
            res[top][i] = A;
        }
        top ++;
        for (int i = top; i <= bottom; i ++) {
            res[i][right] = A;
        }
        right --;
        for (int i = right; i >= left; i --) {
            res[bottom][i] = A;
        }
        bottom --;
        for (int i = bottom; i >= top; i --) {
            res[i][left] = A;
        }
        left ++;
        A --;
    }
    return res;
}
