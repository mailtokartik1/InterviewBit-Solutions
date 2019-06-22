void subsetsByLength(vector<int> &A, int n, vector<int> temp, int index, vector<vector<int> > &B) {

    // If the size of the subset is equal to the required size, push it

    if (temp.size() == n) {
        sort(temp.begin(), temp.end());
        B.push_back(temp);
        temp.clear();
        return;
    }

    // Make all the subsets consisting of an element A[i] and recurse

    for (int i = index; i < A.size(); i ++) {
        temp.push_back(A[i]);
        subsetsByLength(A, n, temp, i + 1, B);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > B;

    // Iterate for getting all the subsets from length 0 to length A.size()

    for (int i = 0; i <= A.size(); i ++) {
        subsetsByLength(A, i, vector<int>(), 0, B);    
    }
    sort(B.begin(), B.end());
    return B;
}
