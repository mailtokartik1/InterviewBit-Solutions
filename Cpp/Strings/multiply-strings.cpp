// Helper function to add 2 strings

string addition(string A, string B) {
    int mini = min(A.size(), B.size());
    if (A.size() == mini) {
        int diff = B.size() - A.size();
        for (int i = 0; i < diff; i ++) {
            A = "0" + A;
        }
    } else if (B.size() == mini) {
        int diff = A.size() - B.size();
        for (int i = 0; i < diff; i ++) {
            B = "0" + B;
        }
    }
    int carry = 0;
    string ans = "";
    for (int i = A.size() - 1; i >= 0; i --) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        ans.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry) {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string Solution::multiply(string A, string B) {

    // Corner case

    if ((A.size() == 1 && A[0] == '0') || (B.size() == 1 && B[0] == '0')) {
        return string("0");
    }
    int mini = min(A.size(), B.size());
    if (B.size() == mini) {
        swap(A, B);
    }
    int count = 0;
    string ans;

    // Loop through the strings to proceed multiplying like in the handwritten way

    for (int i = A.size() - 1; i >= 0; i --) {
        string temp;
        int carry = 0;
        for (int j = B.size() - 1; j >= 0; j --) {
            int mul = (A[i] - '0') * (B[j] - '0') + carry;
            temp.push_back((mul % 10) + '0');
            carry = mul / 10;
        }
        if (carry) {
            temp.push_back(carry + '0');
        }
        reverse(temp.begin(), temp.end());
        for (int i = 0; i < count; i ++) {
            temp += '0';
        }
        ans = addition(ans, temp);
        count ++;
    }
    int i = 0;
    while (ans[i] == '0') {
        i ++;
    }
    if (i != 0) {
        ans.erase(ans.begin(), ans.begin() + i);
    }
    return ans;
}
