int Solution::diffPossible(const vector<int> &A, int B) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }
    bool flag = false;
    unordered_map<int, int> umap;

    // Use a map to check the existence of elements in the array

    for (int i = 0; i < A.size(); i ++) {
        if (umap.find(A[i]) != umap.end()) {
            flag = true;
        } else {
            umap[A[i]] = 1;    
        }
    }

    // Flag identifies the case when B = 0

    if (B != 0) {

        // Check if there exists an element A[i] + B or A[i] - B

        for (int i = 0; i < A.size(); i ++) {
            if (umap.find(A[i] + B) != umap.end() || umap.find(A[i] - B) != umap.end()) {
                return 1;
            }
        }    
    } else return flag;
    return 0;
}
