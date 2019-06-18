vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> C;

    // Corner case

    if (A.size() < 2) {
        return C;
    }

    // Use an unordered map that takes key as the element and value as an array of indices of the element in the array

    unordered_map<int, vector<int>> map;

    // Insert the indices into the map(1 bases indices)

    for (int i = 0; i < A.size(); i ++) {
        map[A[i]].push_back(i + 1);
    }

    // Loop through the array and check if for an element A[i], B - A[i] exists
    // If it does, check if the index is not equal to the current index(for corner case when both the elements are same)

    int index2 = INT_MAX, index1 = INT_MIN;
    int i = 0; int j = A.size() - 1;
    for (int i = 0; i < A.size(); i ++) {
        if (map.find(B - A[i]) != map.end()) {
            int index1Temp = INT_MAX;

            // Loop through the list in the map and choose the first index which is not equal to the current index

            for (int j = 0; j < map[B - A[i]].size(); j ++) {
                if (map[B - A[i]][j] != i + 1) {
                    index1Temp = map[B - A[i]][j];
                    break;
                }
            }

            // Choose index2Temp as the larger element

            int index2Temp = i + 1;
            if (index1Temp > index2Temp) {
                swap(index1Temp, index2Temp);
            }

            // If index2Temp is the smallest one yet, set it to the current one

            if (index2Temp < index2) {
                index2 = index2Temp;
                index1 = index1Temp;
            }
        }
    }
    if (index1 == INT_MIN || index2 == INT_MAX) {
        return C;
    }
    C.push_back(index1);
    C.push_back(index2);
    return C;
}
