int Solution::trap(const vector<int> &A) {
    int n = A.size(), i = 0, ma, tmp = 0, ans = 0;
    stack<int> s;

    // Move ahead to the first non-zero value

    while (i < n && A[i] == 0)
        i++;

    // Loop through the array

    if (i < n) {
        for (int j = i; j < n; j++) {
            tmp = 0;

            // If stack is empty, push the element

            if (s.empty()) {
                s.push(A[j]);
                ma = A[j];

            } else {

                // If the element is less than the previous max, push the element

                if (A[j] < ma)
                    s.push(A[j]);   
                else {

                    // Loop until the stack is empty and add the values to the total
                    // Push the new max element later

                    while (!s.empty()) {
                        tmp += (ma - s.top());
                        s.pop();
                    }
                    s.push(A[j]);
                    ma = A[j];
                    ans += tmp;
                }
            }
        }
    }

    // Handle the ending case

    ma = 0,tmp = 0;
    while (!s.empty()) {
        if (s.top() > ma) ma = s.top();
        else tmp += ma-s.top();
        s.pop();
    }
    return ans + tmp;
}