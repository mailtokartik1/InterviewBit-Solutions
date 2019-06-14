#define MOD 10000003

// isPossibleFunction to check if the number of painters exceed for a value

bool isPossible(int A, int B, vector<int> &C, long long int minTime) {
    long long int curMin = 0;
    int count = 1;
    for (int i = 0; i < C.size(); i ++) {
        if ((C[i]) % MOD > minTime) {
            return false;
        }
        
        if ((curMin + C[i]) % MOD <= minTime) {
            (curMin += C[i]) % MOD;
        } else {
            count ++;
            (curMin = C[i]) % MOD;
        }
    }
    if (count > A) {
        return false;
    }
    return 1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int sum = 0;

    // Sum of all the elements

    for (int i = 0; i < C.size(); i ++) {
        sum += C[i];
    }

    // Binary Search from start to end(possible values)

    long long int maxi = INT_MIN;
    long long int end = ((sum % MOD));
    long long int start = 0;
    long long res = INT_MAX;
    while (start <= end) {
        long long int mid = (start + (end - start) / 2);
        if (isPossible(A, B, C, mid)) {
            res = min(mid, res);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return (res * (long long) B) % MOD;
}
