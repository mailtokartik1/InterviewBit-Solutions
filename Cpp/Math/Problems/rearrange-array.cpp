// We need to remember the indices of the array elements
// so we encode A[i] like A[i] = A[i] + A[A[i]] * n
// % operator on A[i] will give us A[i]
// / operator on A[i] will give us A[A[i]]

void Solution::arrange(vector<int> &A) {
    vector<int> B = A;
    for (int i = 0; i < A.size(); i ++) {
        A[i] += (A[A[i]] % A.size()) * A.size();
    }
    for (int i = 0; i < A.size(); i ++) {
        A[i] = A[i] / A.size();
    }
}
