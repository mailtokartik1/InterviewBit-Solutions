unordered_map<char, string> createMap(unordered_map<char, string> map) {
    map['1'] = "1";
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    map['0'] = "0";
    return map;
}

void combinations(string &A, vector<string> &B, unordered_map<char, string> &map, string temp, int start, int start2) {
    if (temp.size() == A.size()) {
        B.push_back(temp);
        temp.clear();
        return;
    }
    for (int i = start2; i < A.size(); i ++) {
        string temp1 = map[A[i]];
        start = 0;
        for (int j = start; j < temp1.size(); j ++) {
            temp.push_back(temp1[j]);
            combinations(A, B, map, temp, j + 1, i + 1);
            temp.pop_back();
        }
    }
}
vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> map;
    map = createMap(map);
    vector<string> B;
    combinations(A, B, map, string(), 0, 0);
    return B;
}