int Solution::repeatedNumber(const vector<int> &A) {

    // Moore's voting algorithm

    int cand1 = INT_MAX, cand2 = INT_MAX;
    int count1 = 0, count2 = 0;

    // Here we pick 2 candidates for the solution.
    // If a candidate occurs, we increase the count
    // else we decrease the count and make a new candidate

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == cand1) {
            count1 ++;
        } else if (A[i] == cand2) {
            count2 ++;
        } else if (count1 == 0) {
            cand1 = A[i];
            count1 ++;
        } else if (count2 == 0) {
            cand2 = A[i];
            count2 ++;
        } else {
            count1 --;
            count2 --;
        }
    }
    count1 = 0;
    count2 = 0;

    // Here we check if the candidates are worthy or not

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == cand1) {
            count1++;
        } else if (A[i] == cand2) {
            count2 ++;
        }
    }
    if (count1 > A.size() / 3) {
        return cand1;
    }
    if (count2 > A.size() / 3) {
        return cand2;
    }
    return -1;
}
