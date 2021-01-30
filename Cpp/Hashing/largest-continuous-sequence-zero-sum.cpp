vector<int> Solution::lszero(vector<int> &A) {
    int maxi = INT_MIN, i = 0, j = i + 1, sum = 0, index1 = -1, index2 = -1;
    unordered_map<int, int> map;
    bool newCheck = false;
    vector<int> C;
    map[0] = -1;

    // Store the subarray values according to the sum of the subsequence

    for (int i = 0; i < A.size(); i ++) {
        sum += A[i];
        if (map.find(sum) != map.end()) {
            newCheck = true;

            // Compare for the maximum length

            if (i - (map[sum] + 1) + 1 > maxi) {
                maxi = i - (map[sum] + 1) + 1;
                index1 = (map[sum] + 1);
                index2 = i;
            }
        } else {
            map[sum] = i;
        }
    }
    if (newCheck) {
        for (int i = index1; i <= index2 && index1 != -1 && index2 != -1; i ++) {
            C.push_back(A[i]);
        }
    }
    return C;
}
