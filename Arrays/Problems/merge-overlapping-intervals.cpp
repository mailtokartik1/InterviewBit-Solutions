/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Helper function to for comparing Intervals

bool operator > (const Interval &i1, const Interval &i2) {
    if (i1.start < i2.start) {
        return true;
    } else if (i1.start == i2.start) {
        return i1.end > i2.end;
    } else return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> B;

    // corner cases

    if (A.size() <= 0) {
        return B;
    } else if (A.size() == 1) {
        return A;
    }
    map<int, int> C;

    // sort the intervals

    sort(A.begin(), A.end(), greater<Interval>());
    int flag = 1;
    int x = INT_MAX, y=INT_MAX;
    B.push_back(A[0]);

    // check the interval endpoints

    for (int i = 1; i < A.size(); i ++) {
        if (A[i].start > B[B.size() - 1].end) {
            B.push_back(A[i]);
        } else {
            B[B.size() - 1].end = max(B[B.size() - 1].end, A[i].end);
        }
    }
    return B;
}
