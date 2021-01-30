int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char, int> map;
    int i = 0;
    int j = i + 1;

    // Corner case

    if (A.size() < 2) {
        return A.size();
    }
    int maxi = INT_MIN;

    // Start with 2 pointers at the beginning
    // Store the indices of the values in the map
    // Compare for the longeest length

    while (i < A.size() && j < A.size()) {
        map[A[i]] = i;
        if (j == i && j < A.size()) {
            j ++;
        }
        if (map.find(A[j]) != map.end()) {
            maxi = max(maxi, j - i);
            i = map[A[j]] + 1;
            j = i;
            map.clear();
        } else {
            map[A[j]] = j;
            j ++;
        }
    }
    int size = A.size();
    if (j == A.size()) {
        maxi = max(maxi, size - i);
    }
    return maxi;
}
