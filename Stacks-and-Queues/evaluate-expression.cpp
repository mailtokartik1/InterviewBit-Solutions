int val(int A, int B, string c) {
    if (c == "+") {
        return A + B;
    } else if (c == "-") {
        return A - B;
    } else if (c == "*") {
        return A * B;
    } else if (c == "/") {
        return A / B;
    }
}
int Solution::evalRPN(vector<string> &A) {
    stack<int> B;

    // Corner case

    if (A.size() <= 0) {
        return 0;
    }

    // Loop through the array and push numbers on the stack
    // Resolve the operator with the elements in the stack
    // Push the resultant element on the stack

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] != "+" && A[i] != "-" && A[i] != "*" && A[i] != "/") {
            B.push(stoi(A[i]));
        } else {
            int temp1 = B.top();
            B.pop();
            int temp2 = B.top();
            B.pop();
            B.push(val(temp2, temp1, A[i]));
        }
    }
    if (!B.empty()) {
        return B.top();
    }
    return 0;
}
