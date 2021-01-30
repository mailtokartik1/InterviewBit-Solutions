// Alternative solution using DFS is provided below however, it exceeds the time limit

#define MOD 1000000007
typedef long long ll;
ll exponent[1001] = {0};
ll ncr[1001][1001] = {0};

// Precompute ncr

void preComputencr() {
    for (int i = 1; i <= 1000; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0 || j == i) {
                ncr[i][j] = 1;
            } else ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
        }
    }
    return;
}

// Precompute exponent of 2

void preComputeExponent() {
    exponent[0] = 1;
    for (int i = 1; i <= 1000; i ++) {
        exponent[i] = (exponent[i - 1] * 2) % MOD;
    }
    return;
}
int Solution::solve(int A, vector<int> &B) {
    if (B.size() <= 0 || A <= 0) {
        return 0;
    }
    preComputencr();
    preComputeExponent();
    ll res = 1;

    // Sort the visited array to find packets of unvisited cities

    sort(B.begin(), B.end());
    int num = B[0] - 1;
    for (int i = 1; i < B.size(); i ++) {
        int sizePacket = B[i] - B[i - 1] - 1;
        if (sizePacket > 0) {

            // Use the fact that (n1 + n2)C(n2) = (n1 + n2)!/(n1!){n2!) and eliminate the numerator (n1 + n2)! in future terms(Cumulative combination)

            num += sizePacket;
            ll expo = exponent[sizePacket - 1];
            res = ((res * expo) % MOD * ncr[num][sizePacket]) % MOD;
        }
    }
    return (res * ncr[num + A - B[B.size() - 1]][A - B[B.size() - 1]]) % MOD;
}


// Below solution exceeds the time limit!!!

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