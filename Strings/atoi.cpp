int Solution::atoi(const string A) {
    string B;
    int i;
    bool neg = false;

    // Loop through the sting to check if the number is negative and handle space charcaters

    for (i = 0; i < A.size(); i ++) {
        int temp = A[i];
        if (temp >= 48 && temp <= 57) {
            break;
        } else if (A[i] == '-' && i != A.size() - 1 && ((int)A[i + 1] >= 48 && (int)A[i + 1] <= 57)) {
            neg = true;
            i ++;
            break;
        } else if (A[i] == '+' && i != A.size() - 1 && ((int)A[i + 1] >= 48 && (int)A[i + 1] <= 57)) {
            i ++;
            break;
        } else if (A[i] != ' ') {
            return 0;
        }
    }
    int j;

    // Get the index of number character in the string

    for (j = A.size() - 1; j >= 0; j --) {
        int temp = A[j];
        if (temp >= 48 && temp <= 57) {
            break;
        }
    }
    int start;
    start = i;

    // Loop through the string to add the values for the corresponding numbers

    for (int k = start; k <= j; k ++) {
        int temp = A[k];
        if (temp >= 48 && temp <= 57) {
            B += A[k];
        } else {
            break;
        }
    }

    // reverse the string and comvert it into a number

    long long mag = 0;
    bool maxi = false;
    reverse(B.begin(), B.end());
    int count = 0;
    for (i = 0; i < B.size(); i ++, count ++) {
        mag += (B[i] - '0') * pow(10, count);
        if (mag > INT_MAX) {
            maxi = true;
            break;
        }
    }

    // apply overflow and sign check

    if (maxi) {
        if (neg) {
            return INT_MIN;
        } else return INT_MAX;
    }
    if (neg) {
        return -1 * mag;
    }
    return mag;
}
