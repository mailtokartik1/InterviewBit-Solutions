void recursePermute(vector<int> A, int start, int end, vector<vector<int> > &B) {

    // If the starting index is equal to the ending index, push the permutation

    if (start == end) {
        B.push_back(A);
        return;
    }

    // If not, swap every element with the first element and recurse to get all the combinations

    if (start < end) {
        for (int i = start; i <= end; i ++) {
            swap(A[i], A[start]);
            recursePermute(A, start + 1, end, B);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > B;

    // Corner case

    if (A.size() <= 1) {
        B.push_back(A);
        return B;
    }
    recursePermute(A, 0, A.size() - 1, B);
    return B;
}
