#define DIV 1000000007
int Solution::nchoc(int A, vector<int> &B) {
    long long res = 0;
    priority_queue<int> q;
    for (int i = 0; i < B.size(); i ++) {
        q.push(B[i]);
    }
    for (int i = 0; i < A; i ++) {
        if (!q.empty()) {
            int temp = q.top();
            res += temp % DIV;
            q.pop();
            if (floor(temp / 2) != 0) {
                q.push(floor(temp / 2));
            }
        } else {
            break;
        }
    }
    return res % DIV;
}
