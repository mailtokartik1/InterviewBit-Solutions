vector<string> Solution::prettyJSON(string A) {

    // Corner case

    vector<string> B;
    if (A.size() <= 0) {
        return B;
    }
    int countBraces = 0;
    string temp, temp2;

    // Space character handling

    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == ' ' && i != A.size() - 1) {
            A.erase(A.begin() + i, A.begin() + i + 1);
            i --;
        }
    }
    if (A[A.size() - 1] == ' ') {
        A.erase(A.end() - 1, A.end());
    }
    bool sameLine = true;

    // Loop through the string to check for indentation

    for (int i = 0; i < A.size(); i ++) {
        if (sameLine) {
            temp += A[i];

            // Specific character handling

            if (A[i] == '{' || A[i] == '[') {
                countBraces ++;
                sameLine = false;
                B.push_back(temp);
                temp.clear();
            } else if (A[i] == ',' || (A[i] == ':' && (A[i + 1] == '{' || A[i + 1] == '['))) {
                sameLine = false;
                B.push_back(temp);
                temp.clear();
            } else if (A[i] == '}' || A[i] == ']') {
                temp.erase(temp.end() - 1, temp.end());
                countBraces --;
                sameLine = false;
                B.push_back(temp);
                temp.clear();
                i --;
            }
        } else {
            if (A[i] == '}' || A[i] == ']') {
                for (int j = 0; j < countBraces; j ++) {
                    temp += '\t';
                }
                temp += A[i];
                if (A[i + 1] == ',') {
                    temp += A[i + 1];
                    sameLine = false;
                    B.push_back(temp);
                    temp.clear();
                    i ++;
                    continue;
                }
                B.push_back(temp);
                temp.clear();
                countBraces --;
            } else {
                for (int j = 0; j < countBraces; j ++) {
                    temp += '\t';
                }
                sameLine = true;
                i --;
            }
        }
    }
    return B;
}
