void combine(vector<int> A, int index, vector<int> temp, int B, vector<vector<int> > &C) {

    // If the desired sum is less than the required sum, return
    // If the desired sum is equal to the required sum, push it

    if (B < 0) {
        return;
    }
    if (B == 0) {
        sort(temp.begin(), temp.end());
        C.push_back(temp);
        return;
    }

    // Unlike the similar question, this time, we increment the index to not use the same element more than once

    for (int i = index; i < A.size(); i ++) {
        temp.push_back(A[i]);
        combine(A, i + 1, temp, B - A[i], C);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > C;

    // Sort the original array to get a sorted matrix

    sort(A.begin(), A.end());
    combine(A, 0, vector<int>(), B, C);

    // Remove the duplicates

    C.erase(unique(C.begin(), C.end()), C.end());
    return C;
}
