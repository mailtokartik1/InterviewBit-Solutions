bool isPalindrome(string A) {
    string B = A;
    reverse(A.begin(), A.end());
    return A == B;
}
void palindromePartition(string A, vector<string> temp, vector<vector<string>> &B, int index) {
    if (index == A.size()) {
        B.push_back(temp);
        return;
    }
    if (index > A.size()) {
        return;
    }
    int i = index;
    for (int j = 1; j <= A.size(); j ++) {
        string temp1 = A.substr(i, j);
        if (isPalindrome(temp1)) {
            temp.push_back(A.substr(i, j));
            palindromePartition(A, temp, B, i + j);
            temp.pop_back();
        }
    }
    return;
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > B;
    palindromePartition(A, vector<string>(), B, 0);
    return B;
}
