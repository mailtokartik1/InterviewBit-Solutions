int Solution::isValidSudoku(const vector<string> &A) {
    unordered_map<int, int> map;

    // Check if a number is repeated in every row

    for (int i = 0; i < A.size(); i ++) {
        for (int j = 0; j < A[i].size();j ++) {
            if (A[i][j] != '.') {
                if (map.find(A[i][j] - '0') != map.end()) {
                    return 0;
                } else {
                    map[A[i][j] - '0'] = 1;
                }    
            }
        }
        map.clear();
    }

    // Check if a number is repeated in every column

    for (int i = 0; i < A.size(); i ++) {
        for (int j = 0; j < A[i].size();j ++) {
            if (A[j][i] != '.') {
                if (map.find(A[j][i] - '0') != map.end()) {
                    return 0;
                } else {
                    map[A[j][i] - '0'] = 1;
                }    
            }
        }
        map.clear();
    }

    // Check the 3X3 matrices for a repeated number

    for (int m = 0; m < 3; m ++) {
        for (int n = 0; n < 3; n ++) {
            for (int i = m * 3; i < m * 3 + 3; i ++) {
                for (int j = n * 3; j < n * 3 + 3;j ++) {
                    if (A[i][j] != '.') {
                        if (map[A[i][j] - '0'] == 1) {
                            return 0;
                        } else {
                            map[A[i][j] - '0'] = 1;
                        }    
                    }
                }
            }
            map.clear();
        }
    }
    return 1;
}

