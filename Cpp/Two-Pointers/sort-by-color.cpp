void Solution::sortColors(vector<int> &A) {
    int countA = 0, countB = 0, countC = 0;

    // Keep 3 count variables and push them one by one after clearing the array

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == 0) {
            countA ++;
        } else if (A[i] == 1) {
            countB ++;
        } else if (A[i] == 2) {
            countC ++;
        }
    }
    A.clear();
    for (int i = 0; i < countA; i ++) {
        A.push_back(0);
    }
    for (int i = 0; i < countB; i ++) {
        A.push_back(1);
    }
    for (int i = 0; i < countC; i ++) {
        A.push_back(2);
    }]
}
