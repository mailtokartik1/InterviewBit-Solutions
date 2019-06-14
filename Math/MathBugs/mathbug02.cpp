vector<vector<int> > Solution::squareSum(int A) {
    vector<vector<int> > ans;
    for (long long int a = 0; a * a < A; a++) {
        for (long long int b = a; b * b < A; b++) {
            if (a * a + b * b == A) {
                vector<int> newEntry; 
                newEntry.push_back(a);
                newEntry.push_back(b);
                ans.push_back(newEntry);
            }
        }
    }
    return ans;
}
