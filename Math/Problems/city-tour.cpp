// This solution exceeds the time limit!!!I will try again soon.

// we can pick up K places in our walk list N!/(N-K)!/K! different ways

vector<int> mem(1000);
vector<int> eligible1(vector<int> visit) {
    vector<int> eligible;
    for (int i = 0; i < visit.size(); i ++) {
        if (visit[i] == 0) {
            if (i != 0 && i != visit.size() - 1) {
                if (visit[i - 1] == 1 || visit[i + 1] == 1) {
                    eligible.push_back(i + 1);
                }
            } else if (i == 0) {
                if (visit[i + 1] == 1) {
                    eligible.push_back(i + 1);
                }
            } else if (i == visit.size() - 1) {
                if (visit[i - 1] == 1) {
                    eligible.push_back(i + 1);
                }
            }
        }
    }
    return eligible;
}
vector<int> orign(vector<int> visit, int A) {
    visit[A - 1] = 1;
    return visit;
}
long long int tot(vector<int> visit, vector<int> eligibleV) {
    mem.clear();
    if (eligibleV.size() == 0) {
        return 1;
    } else {
        long long int sum = 0;
        for (int i = 0; i < eligibleV.size(); i ++) {
            sum += tot(orign(visit, eligibleV[i]), eligible1(orign(visit, eligibleV[i]))) % (int)(pow(10, 9) + 7);
        }
        return sum;
    }
}
int Solution::solve(int A, vector<int> &B) {

    // Corner case

    if (A <= 0 || B.size() <= 0) {
        return 0;
    }
    vector<int> visit(A);
    for (int i = 0; i < B.size(); i ++) {
        visit[B[i] - 1] = 1;
    }
    vector<int> temp = eligible1(visit);
    return tot(visit, temp) % (int)(pow(10, 9) + 7);
}