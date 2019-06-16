int Solution::isValid(string A) {
    stack<int> s;

    // Corner case

    if (A.size() <= 0) {
        return 0;
    } else if (A[0] == ')' || A[0] == ']' || A[0] == '}') {
        return 0;
    }

    // Close corresponding brackets and if the stack is empty or the brackets do not match, return 0
    // At the end, if the stack is empty return 1 else 0

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{') {
            s.push(A[i]);
        } else if (A[i] == ')') {
            if (s.top() == '(') {
                s.pop();
            } else return 0;
        } else if (A[i] == ']') {
            if (s.top() == '[') {
                s.pop();
            } else return 0;
        } else if (A[i] == '}') {
            if (s.top() == '{') {
                s.pop();
            } else return 0;
        }
    }
    return s.empty();
}
