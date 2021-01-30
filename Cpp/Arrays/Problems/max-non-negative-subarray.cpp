vector<int> Solution::maxset(vector<int> &A) {
    vector<int> B;
    vector<pair<int, int>> C;

    // Corner case

    if (A.size() <= 0) {
        return B;
    }

    // Initialize current left, maxleft and max right(index will be current right)

    int L = -1, curL = 0, R = -1;
    long long int until_here = 0, maxi = INT_MIN;

    // Modified Kadane's algorithm

    for (int i = 0; i < A.size(); i ++) {
        until_here += A[i];
        
        if (until_here > maxi && until_here >= 0) {
            maxi = until_here;
            R = i;
            L = curL;
            C.clear();
            pair<int, int> temp;
            temp.first = L;
            temp.second = R;
            C.push_back(temp);
        } else if (until_here == maxi) {
            pair<int, int> temp;
            temp.first = curL;
            temp.second = i;
            C.push_back(temp);
        }
        
        if (until_here < 0 || A[i] < 0) {
            until_here = 0;
            curL = i + 1;
        }
    
    }
    int minI, maxI, maxV = INT_MIN;
    if (L == -1 && R == -1) {
        return B;
    } else {
        for (int i = 0; i < C.size(); i ++) {
            int diff = C[i].second - C[i].first;
            if (diff > maxV) {
                maxV = diff;
                minI = C[i].first;
                maxI = C[i].second;
            }
        }
    }
    for (int i = minI; i <= maxI; i ++) {
        B.push_back(A[i]);
    }
    return B;
}
