int Solution::solve(string A) {
    int count = 0;

    // Store the vowels in a map

    map<char, int> B;
    B['A'] = 1;
    B['a'] = 1;
    B['E'] = 1;
    B['e'] = 1;
    B['I'] = 1;
    B['i'] = 1;
    B['O'] = 1;
    B['o'] = 1;
    B['U'] = 1;
    B['u'] = 1;

    // Loop through the array and if the value exists, increment the count

    for (int i = 0; i < A.size(); i ++) {
        if (B[A[i]]) {
            count += (A.size() - i) % 10003;
        }
    }
    return count % 10003;
}
