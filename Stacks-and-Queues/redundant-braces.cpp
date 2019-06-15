int Solution::braces(string A) {
    stack<int> B;

    // Push elements in the stack except ending brace and characters
    // We cancel corresponding braces by popping from stack
    // If there is no operator between 2 braces, there is redundancy
    
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] =='(' || A[i] == '+' || A[i] == '*' || A[i] == '-' || A[i] == '/') {
            B.push(A[i]);
        } else if (A[i] == ')') {
            if (B.top() == '(') {
                return 1;
            } else {
                while (!B.empty() && B.top() != '(') {
                    B.pop();
                }
                B.pop();
            } 
        }
    }
    return 0;
}
