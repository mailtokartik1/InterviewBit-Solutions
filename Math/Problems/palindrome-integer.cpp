int Solution::isPalindrome(int A) {

    // Corner case

    if (A < 0) {
        return 0;
    }
    if (A == 0) {
        return 1;
    }
    vector<int> B;
    int C = A;

    // Extract the digits

    while (A >= 1) {
        B.push_back(A % 10);
        A = A / 10;
    }

    // check if reverse of the number is the same as the number

    long long int num = 0;
    for (int i = 0; i < B.size(); i ++) {
        num += B[i] * pow(10, B.size() - 1 - i);
    }
    return num == C;
}
