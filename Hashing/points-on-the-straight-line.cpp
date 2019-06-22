int Solution::maxPoints(vector<int> &A, vector<int> &B) {

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }
    int maxi = 1;
    unordered_map<float, int> map;

    // Store the slopes of the lines in a map
    // Also keep a track of the identical points and points on a vertical line
    // Every non-identical points will be on a line

    for (int i = 0; i < A.size(); i ++) {
        int duplicates = 1, verticals = 0;
        for (int j = i + 1; j < B.size(); j ++) {
            float slope;
            if (A[i] == A[j]) {
                if (B[i] == B[j]) {
                    duplicates ++;
                } else {
                    verticals ++;
                }
            } else {
                if (B[i] != B[j]) {
                    slope = (A[j] - A[i]) / (float)(B[j] - B[i]);
                } else slope = 0.0;
                if (map.find(slope) != map.end()) {
                    map[slope] ++;
                } else map[slope] = 1;   
            }
        }

        // Find the maximum number of points from the map
        // Whilst keeping track of the verticals and the duplicates

        for (unordered_map<float, int>::iterator it = map.begin(); it != map.end(); it ++) {
            maxi = max(maxi, it -> second + duplicates);
        }
        maxi = max(verticals + duplicates, maxi);
        map.clear();
    }
    return maxi;
}
