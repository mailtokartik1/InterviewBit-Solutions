vector<int> Solution::plusOne(vector<int> &A) {

    //Corner case

    vector<int> B;
    if (A.size() <= 0) {
        return B;
    }

    // Get rid of all the empty values at the beginning

    int start = 0;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] != 0) {
            start = i;
            break;
        }
    }

    // Check 2 cases of A[i] equal to or not equal to 9
    
    for (int i = A.size() - 1; i >= start; i --) {
        if (A[i] != 9) {
            A[i] ++;
            break;
        } else if (A[i] == 9) {
            A[i] = 0;
            if (i == start) {
                A.push_back(1);

                // Reverse the array on completion

                reverse(A.begin(), A.end());
                break;
            }
        }
    }

    // Erase empty spots

    if (start != 0) {
        A.erase(A.begin(), A.begin() + start);
    }
    return A;
}
