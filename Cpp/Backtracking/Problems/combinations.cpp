void combination(int A, int num, int pos, vector<int> temp, vector<vector<int> > &C) {

    // If the size of the combination is equal to the required size, push it

    if (temp.size() == num) {
        sort(temp.begin(), temp.end());
        C.push_back(temp);
        temp.clear();
        return;
    }

    // Make all the combinations consisting of an element A[i] and recurse

    for (int i = pos; i <= A; i ++) {
        vector<int> temp2 = temp;
        temp2.push_back(i);
        combination(A, num, i + 1, temp2, C);
    }
    
}
vector<vector<int> > Solution::combine(int A, int num) {
    vector<vector<int> > C;
    if (num > A) {
        return C;
    }
    combination(A, num, 1, vector<int>(), C);
    return C;
}
