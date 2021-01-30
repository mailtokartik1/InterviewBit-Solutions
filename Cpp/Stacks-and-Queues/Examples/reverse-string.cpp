string Solution::reverseString(string A) {
    stack<char> B;

    // Push sequentially in the stack

    for (int i = 0; i < A.size(); i ++) {
        B.push(A[i]);
    }
    A.clear();

    // Pop from the stack and push in the returning string

    while (!B.empty()) {
        A.push_back(B.top());
        B.pop();
    }
    return A;
}

