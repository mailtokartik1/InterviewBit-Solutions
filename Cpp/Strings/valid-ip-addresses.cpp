// Helper function to check for valid numbers in a string

bool check(string s)
{
    int x = stoi(s);
    if(x > 255)
        return false;
    string y = to_string(x);
    if(y != s)
        return false;
    return true;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> B;

    // Corner case

    if (A.size() < 4 || A.size() > 12) {
        return B;
    }

    // Loop through the string to split it into 3 parts for the numbers and check them individually

    for (int i = 1; i < A.size(); i ++) {
        for (int j = i + 1; j < A.size(); j ++) {
            for (int k = j + 1; k < A.size(); k ++) {
                int first = stoi(A.substr(0, i));
                int second = stoi(A.substr(i, j - i));
                int third = stoi(A.substr(j, k - j));
                int fourth = stoi(A.substr(k));
                if (first >= 0 && first <= 255 && second >= 0 && second <= 255 && third >= 0 && third <= 255 && fourth >= 0 && fourth <= 255 && check(A.substr(0, i)) && check(A.substr(i, j - i)) && check(A.substr(j, k - j)) && check(A.substr(k))) {
                    string temp = to_string(first) + "." + to_string(second) + "." + to_string(third) + "." + to_string(fourth);
                    B.push_back(temp);
                }
            }
        }
    }
    return B;
}

// Alternate solution using recursion

// Helper function to check validity of a string

bool checkValidNum(string a) {
    return a.size() > 1 && a[0] == '0' ? 0 : stoll(a) >= 0 && stoll(a) <= 255;
}

// Helper function to check validity of a whole IP

bool checkValidIP(string a) {
    int occurences = count(a.begin(), a.end(), '.');
    if (occurences != 3) {
        return 0;
    }
    int start = 0;
    while (a.find('.', start) != string::npos) {
        string temp = a.substr(start, a.find('.', start) - start);
        if (!checkValidNum(temp)) {
            return 0;
        }
        start = a.find('.', start) + 1;
    }
    return checkValidNum(a.substr(start));
}

// Helper function to generate all possibilities

void generate (string A, vector<string> &res, int index, string local) {
    if (index >= A.size()) {
        if (checkValidIP(local)) {
            res.push_back(local);
        }
        return;
    }
    for (int i = 1; i <= A.size() - index; i ++) {
        string temp = A.substr(index, i);
        generate(A, res, index + i, local.size() ? local + "." + temp : temp);
    }
    return;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res;
    generate(A, res, 0, string());
    return res;
}


