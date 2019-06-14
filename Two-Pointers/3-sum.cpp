
int Solution::threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int bestSum = 1000000000, sum = 0;
    // Fix the smallest number in the three integers
    for (int i = 0; i < num.size() - 2; i++) {
        // Now num[i] is the smallest number in the three integers in the solution
        int ptr1 = i + 1, ptr2 = num.size() - 1;
        while (ptr1 < ptr2) {
            sum = num[i] + num[ptr1] + num[ptr2];
            if (abs(target - sum) < abs(target - bestSum)) {
                bestSum = sum;
            }
            if (sum > target) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
    }
    return bestSum;
}

