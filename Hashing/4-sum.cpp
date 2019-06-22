vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> C;
    vector<int> temp;

    // Run 4 loops and check for the solution(I know this is the naive solution, I'll work on it again later)
    // Watch this space for a cleaner solution in the future

    for (int i = 0; i < A.size(); i ++) {
        for (int j = i + 1; j < A.size(); j ++) {
            for (int m = j + 1; m < A.size(); m ++) {
                for (int n = m + 1; n < A.size(); n ++) {
                    if (A[i] + A[j] + A[m] + A[n] == B && i != j && j != m && m != n) {
                        temp.push_back(A[i]);
                        temp.push_back(A[j]);
                        temp.push_back(A[m]);
                        temp.push_back(A[n]);
                        sort(temp.begin(), temp.end());
                        C.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
    }
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    return C;
}

