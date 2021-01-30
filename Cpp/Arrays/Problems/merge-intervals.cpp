/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Helper function to compare the values in Interval

bool operator > (const Interval &a, const Interval &b) {
    if (a.start > b.start) {
        return false;
    } else if (a.start < b.start) {
        return true;
    } else {
        a.end < b.end ? 1 : 0;
    }
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> B;
    intervals.push_back(newInterval);

    // sort the intervals using the helper function

    sort(intervals.begin(), intervals.end(), greater<Interval>());

    B.push_back(intervals[0]);

    // Compare the intervals end points

    for (int i = 1; i < intervals.size(); i ++) {
        if (B[B.size() - 1].end >= intervals[i].start) {
            B[B.size() - 1].end = max(B[B.size() - 1].end, intervals[i].end);
        } else {
            B.push_back(intervals[i]);
        }
    }
    return B;
}
