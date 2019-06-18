vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> B;
    vector<string> C = A;

    // Use a map with key as the sorted value of a string and value as a vector of integers

    unordered_map<string, vector<int>> umap;

    string temp;

    // Corner case

    if (A.size() <= 0) {
        return B;
    }

    // Push the indices in the specified array based on the sorting value

    for (int i = 0; i < C.size(); i ++) {
        temp = C[i];
        sort(C[i].begin(), C[i].end());
        umap[C[i]].push_back(i + 1);
    }

    // Iterate through the map

    for (unordered_map<string, vector<int>>::iterator it = umap.begin(); it != umap.end(); it ++) {
        sort(it -> second.begin(), it -> second.end());
        B.push_back(it -> second);
    }
    return B;
}
