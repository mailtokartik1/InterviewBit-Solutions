void Solution::reverseWords(string &A) {
    int spaceCount = 0;
    int i, start, end;

    // Handle space characters

    for (i = 0; i < A.size(); i ++) {
        if (A[i] != ' ') {
            break;
        }
    }
    start = i;
    if (start == A.size()) {
        return;
    }
    for (i = A.size() - 1; i >= 0; i --) {
        if (A[i] != ' ') {
            break;
        }
    }
    end = i;
    for (i = start; i <= end; i ++) {
        if (A[i] == ' ') {
            if (A[i + 1] == ' ') {
                A.erase(A.begin() + i, A.begin() + i + 1);
                i --;
            }
        } 
    }
    string s, temp;
    reverse(A.begin(), A.end());

    // Get the last word from the end of the word-reversed string

    for (i = 0; i < A.size(); i ++) {
        if (A[i] != ' ') {
            temp.push_back(A[i]);
        } else {
            reverse(temp.begin(), temp.end());
            s += temp;
            s += ' ';
            temp.clear();
        }
    }
    if (temp.size() != 0) {
        reverse(temp.begin(), temp.end());
        s += temp;
    }
    A = s;
}
