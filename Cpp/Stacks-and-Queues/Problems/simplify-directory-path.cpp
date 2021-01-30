string Solution::simplifyPath(string A) {
    stack<string> s;

    // Maintain a stack of all the values between the / / slashes
    // Pop and push the values according to A[i]

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == '/') {
            string p = "";
            i ++;
            while (A[i] != '/' && i < A.size()) {
                p += A[i];
                i ++;
            }
            if (p == "..") {
                if (!s.empty()) {
                    s.pop();    
                }
            } else if (p != "" && p != ".") {
                s.push(p);
            }
            i --;
        }
    }

    // Now we have the final directoy structure but we need to reverse the stack

    stack<string> temp;
    string ans;
    if (s.empty()) {
        return "/";
    }

    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    // Append '/' to the values of the stack

    while (!temp.empty()) {
        ans += "/";
        ans += temp.top();
        temp.pop();
    }
    return ans;
}