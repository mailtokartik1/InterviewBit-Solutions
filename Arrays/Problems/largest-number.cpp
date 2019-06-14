// Helper function to compare values in the array

bool comp (int A, int B) {
    string tempAa = to_string(A);
    string tempBb = to_string(B);
    string c1 = tempAa + tempBb;
    string c2 = tempBb + tempAa;
    return c1.compare(c2) > 0 ? 1 : 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end(), comp);
    string ans;
    int countZero = 0;
    for (int i = 0; i < B.size(); i ++) {
        if (B[i] == 0) {
            countZero ++;
        }
        ans += to_string(B[i]);
    }
    if (countZero == B.size()) {
        return string(to_string(0));
    }
    return ans;
}
