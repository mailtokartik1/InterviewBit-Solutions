#define MOD 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {
    if (A.size() <= 0) {
        return 0;
    }
    vector<int> next(A.size());
    vector<int> prev(A.size());
    stack<pair<int, int>> st;

    // Make next greater array

    for (int i = A.size() - 1; i >= 0; i --) {
        if (st.empty()) {
            next[i] = 0;
        } else {
            while (!st.empty() && st.top().first <= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next[i] = st.top().second;
            } else next[i] = 0;
        }
        st.push(make_pair(A[i] % MOD, i));
    }
    while (!st.empty()) {
        st.pop();
    }

    // Make prev greater array

    for (int i = 0; i < A.size(); i ++) {
        if (st.empty()) {
            prev[i] = 0;
        } else {
            while (!st.empty() && st.top().first <= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev[i] = st.top().second;
            } else prev[i] = 0;
        }
        st.push(make_pair(A[i] % MOD, i));
    }
    long long maxi = 0;
    for (int i = 0; i < A.size(); i ++) {
        long long temp = ((long long)next[i] * (long long)prev[i]);
        maxi = max(maxi, temp);
    }
    return maxi % MOD;
}
