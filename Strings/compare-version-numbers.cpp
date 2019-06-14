// Helper function to compare 2 version strings

int stringVal(string A, string B) {
    int i = 0;
    while (A[i] == '0') {
        i ++;
    }
    A.erase(A.begin(), A.begin() + i);
    i = 0;
    while (B[i] == '0') {
        i ++;
    }
    B.erase(B.begin(), B.begin() + i);
    if (A.size() > B.size()) {
        return 1;
    } else if (A.size() < B.size()) {
        return -1;
    } else {
        for (int j = 0; j < A.size(); j ++) {
            if (A[j] != B[j]) {
                if (A[j] > B[j]) {
                    return 1;
                } else if (A[j] < B[j]) {
                    return -1;
                }
            }
        }
    }
    return 0;
}
int Solution::compareVersion(string A, string B) {
    int dotA = 0;
    int dotB = 0;

    // Count the number of . characters in the version numbers

    for(int i = 0; i < A.size(); i ++) {
        if (A[i] == '.') {
            dotA ++;
        }
    }
    for(int i = 0; i < B.size(); i ++) {
        if (B[i] == '.') {
            dotB ++;
        }
    }

    // Make the number of dot characters equal in both strings by appending '.0'

    if (dotA > dotB) {
        for (int i = 0; i < dotA - dotB; i ++) {
            B += ".0";
        }
    } else if (dotA < dotB) {
        for (int i = 0; i < dotB - dotA; i ++) {
            A += ".0";
        }
    }
    int dots = max(dotA, dotB);
    int i = 0;
    int j = 0;
    if (dots == 0) {
        return stringVal(A, B);
    }

    // Compare the version numbers by looping through the arrays and the number of dots

    for (int k = 0; k <= dots; k ++) {
        string tempA;
        string tempB;
        while (A[i] != '.' && i < A.size()) {
            tempA += A[i];
            i ++;
        }
        while (B[j] != '.' && j < B.size()) {
            tempB += B[j];
            j ++;
        }
        if (stringVal(tempA, tempB) == 1) {
            return 1;
        } else if (stringVal(tempA, tempB) == -1) {
            return -1;
        } else if (stringVal(tempA, tempB) == 0) {
            i ++;
            j ++;
            continue;
        }
    }
    return 0;
}
