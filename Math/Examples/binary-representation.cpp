string Solution::findDigitsInBinary(int A) {
    string sol;

    // corner case

    if (A == 0) {
        sol.push_back(48);
        return sol;
    }

    // get divisor and remainder via the loop

    while (A >= 1) {
        if (A % 2 == 0) {
            sol.push_back(48);
        } else if (A % 2 == 1) {
            sol.push_back(49);
        }
        A = A / 2;
    }
    reverse(sol.begin(), sol.end());
    return sol;
}
