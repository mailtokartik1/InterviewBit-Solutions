int binaryToInt(string A) {
    int val = 0;
    for (int i = A.size() - 1; i >= 0; i --) {
        val += (A[i] - '0') * pow(2, A.size() - i - 1);
    }
    return val;
}
void grayCodeUtil(vector<int>& res, int n, int& num) {
    if (n == 0) { 
        res.push_back(num); 
        return; 
    }
    grayCodeUtil(res, n - 1, num);
    num = num ^ (1 << (n - 1)); 
    grayCodeUtil(res, n - 1, num); 
}
vector<int> Solution::grayCode(int A) {
    string B;
    vector<string> C;
    vector<int> D;
    for (int i = 0; i < A; i ++) {
        B += '0';
    }
    int num = 0;
    grayCodeUtil(D, A, num);
    for (vector<string>::iterator it = C.begin(); it != C.end(); it ++) {
        D.push_back(binaryToInt(*it));
    }
    return D;
}
