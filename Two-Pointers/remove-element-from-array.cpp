int Solution::removeElement(vector<int> &A, int B) {

    // count the number of elements in the array other than the given element

    int count = 0;
    for (int i = 0; i < A.size(); i++) { 
        if (A[i] == B) continue;
        else {
            A[count] = A[i];
            count++;
        }
    }
    return count;
}
