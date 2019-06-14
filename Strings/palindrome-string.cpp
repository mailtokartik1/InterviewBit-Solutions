int Solution::isPalindrome(string A) {
    string B, C;

    // Loop through the string and convert the string to lowercase
    // Push the alphanumeric characters into a new string
    // Reverse the new string for comparison

    for (int i = 0; i < A.size(); i ++) {
        int temp = A[i];
        if ((temp >= 48 && temp <= 57) || (temp >= 65 && temp < 91) || (temp >= 97 && temp < 123)) {
            if (temp >= 65 && temp < 91) {
                char c = temp + 32;
                A[i] = c;
            }
            B.push_back(A[i]);
        }
    }
    C = B;
    reverse(C.begin(), C.end());
    //cout << B << " " << C;
    return B == C;
}
