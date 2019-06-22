void combine(vector<int> &A, int B, vector<int> temp, int index, vector<vector<int> > &C) {

    // If the desired sum is less than the required sum, return
    // If the desired sum is equal to the required sum, push it

    if (B < 0) {
        return;
    }

    if (B == 0) {
        sort(temp.begin(), temp.end());
        C.push_back(temp);
        temp.clear();
        return;
    }

    // Try out all the combinations consisting of an element A[i] and reduce the required sum by the same amount

    for (int i = index; i < A.size(); i ++) {
        temp.push_back(A[i]);
        combine(A, B - A[i], temp, i, C);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > C;

    // Sort and remove all the duplicates in A

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    combine(A, B, vector<int>(), 0, C);
    return C;
}
