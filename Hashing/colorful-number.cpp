int Solution::colorful(int A) {
    string B = to_string(A);
    string k;
    long long int mul = 1;
    unordered_map<int, vector<string>> C;

    // Hash the values according to the multiplication value of individual digits in the substrings

    for (int i = 1; i <= B.size(); i ++) {
        for (int j = 0; j < B.size(); j += 1) {
            if (j + i > B.size()) {
                break;
            }
            k = B.substr(j, i);
            for (int p = 0; p < k.size(); p ++) {
                mul = mul * (k[p] - '0');
            }
            C[mul].push_back(k);
            mul = 1;
        }
    }

    // If any subsequence has more than one member, return 0 else return 1

    for (unordered_map<int, vector<string>>::iterator it = C.begin(); it != C.end(); it ++) {
        if (it -> second.size() > 1) {
            return 0;
        }
    }
    return 1;
}
