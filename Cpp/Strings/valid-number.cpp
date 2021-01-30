bool checkNumber(string A, int i){

    // Handle spcae characters
    
    while (isspace(A[i])) {
        i ++;
    }
    
    if (i == A.size()) {
        return 0;
    }
    
    while (isspace(A[A.size()-1])) {
        A.pop_back();
    }
    
    int eflag = 0;
    int sflag = 0;
    int dflag = 0;
    int nflag = 0;

    // Handle number characters
    
    while (i < A.size()) {
        if (isdigit(A[i])) {
            i++;
            nflag = 1;
        }
        else {

            // Handle e character

            if (A[i] == 'e') {
                if (nflag == 0) {
                    return 0;
                }
                eflag = 1;
                sflag = 0;
                dflag = 0;
                nflag = 0;
                i ++;
                if (i == A.size()) {
                    return 0;
                }
            }
            else if (A[i] == '+' || A[i] == '-') {
                i ++;
                if (i == A.size()) {
                    return 0;
                }
                if (sflag == 0) {
                    sflag = 1;
                }
                else {
                    return 0;
                }
                if (nflag == 0) {
                    sflag = 1;
                }
                else {
                    return 0;
                }
            }

            // Handle . character

            else if (A[i] == '.') {
                if (dflag == 0) {
                    dflag = 1;
                }
                else {
                    return 0;
                }
                if (eflag == 1) {
                    return 0;
                }
                nflag = 1;
                i ++;
                if (i == A.size()) {
                    return 0;
                }
                else if (!isdigit (A[i])) {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
    }
    
    return 1;  
}

int Solution::isNumber(const string B) {
    return checkNumber(B, 0);
}
